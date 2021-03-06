      PROGRAM ZQCBJ

C
C***DATE WRITTEN   830501   (YYMMDD)
C***REVISION DATE  890801, 930101   (YYMMDD)
C
C                *** A DOUBLE PRECISION ROUTINE ***
C
C     ZQCBJ IS A QUICK CHECK ROUTINE FOR THE COMPLEX J BESSEL FUNCTION
C     GENERATED BY SUBROUTINE ZBESJ.
C
C     ZQCBJ GENERATES SEQUENCES OF J AND H BESSEL FUNCTIONS FROM ZBESJ
C     AND ZBESH AND CHECKS THE WRONSKIANS
C
C     J(FNU,Z)*H(FNU+1,1,Z)-J(FNU+1,Z)*H(FNU,1,Z)=2/(PI*I*Z)   Y.GE.0
C
C     J(FNU,Z)*H(FNU+1,2,Z)-J(FNU+1,Z)*H(FNU,2,Z)=-2/(PI*I*Z)  Y.LT.0
C
C     IN THEIR RESPECTIVE HALF PLANES.
C
C     THE PARAMETER MQC CAN HAVE VALUES 1 (THE DEFAULT) FOR A FASTER,
C     LESS DEFINITIVE TEST OR 2 FOR A SLOWER, MORE DEFINITIVE TEST.
C
C     MACHINE CONSTANTS ARE DEFINED IN FUNCTIONS I1MACH, R1MACH, AND
C     D1MACH. THESE MUST BE SELECTED BY THE USER OR SET ACCORDING TO
C     PROLOGUE INSTRUCTIONS.
C
C     COMPLEX Z, WR, CJ, CH, CON, T1, T2, CER
      EXTERNAL ZABS
      DOUBLE PRECISION AA, AB, AER, ALIM, ATOL, CONR, CONI, WRR, WRI,
     * CERR, CERI, CT, DIG, ELIM, EPS, ER, ERTOL, FNU, FNUL, GNU, HPI,
     * PI, R, RL, RM, R1M4, R1M5, R2, ST, STR, STI, TOL, T1R, T1I, T2R,
     * T2I, T, XNU, ZI, ZR, D1MACH, ZABS, FILM, SLAK, TS, SGN, CJR, CJI,
     * CHR, CHI
      INTEGER I, ICASE, IL, IR, IRB, IT, ITL, K, KK, KODE, K1, K2,
     * LFLG, LUN, M, MFLG, N, NU, NZJ, NZH, I1MACH, KEPS, KDO, NL,
     *NUL, MQC, IERRJ, IERRH
      DIMENSION T(20), AER(25), XNU(20), CJR(20), CJI(20), CHR(20),
     * CHI(20), KEPS(20), KDO(20)
      DATA LUN /7/
      PARAMETER (MQC=1)
      OPEN(LUN, FILE='ZQCBJ.OUT')
C-----------------------------------------------------------------------
C     SET PARAMETERS RELATED TO MACHINE CONSTANTS.
C     TOL IS THE APPROXIMATE UNIT ROUNDOFF LIMITED TO 1.0E-18.
C     ELIM IS THE APPROXIMATE EXPONENTIAL OVER- AND UNDERFLOW LIMIT.
C     EXP(-ELIM).LT.EXP(-ALIM)=EXP(-ELIM)/TOL    AND
C     EXP(ELIM).GT.EXP(ALIM)=EXP(ELIM)*TOL       ARE INTERVALS NEAR
C     UNDERFLOW AND OVERFLOW LIMITS WHERE SCALED ARITHMETIC IS DONE.
C     RL IS THE LOWER BOUNDARY OF THE ASYMPTOTIC EXPANSION FOR LARGE Z.
C     DIG = NUMBER OF BASE 10 DIGITS IN TOL = 10**(-DIG).
C     FNUL IS THE LOWER BOUNDARY OF THE ASYMPTOTIC SERIES FOR LARGE FNU
C-----------------------------------------------------------------------
      R1M4 = D1MACH(4)
      TOL = DMAX1(R1M4,1.0D-18)
      AA = -DLOG10(R1M4)
      K1 = I1MACH(15)
      K2 = I1MACH(16)
      R1M5 = D1MACH(5)
      K = MIN0(ABS(K1),ABS(K2))
      ELIM = 2.303D0*(DBLE(FLOAT(K))*R1M5-3.0D0)
      AB = AA*2.303D0
      ALIM = ELIM + DMAX1(-AB,-41.45D0)
      DIG = DMIN1(AA,18.0D0)
      FNUL = 10.0D0 + 6.0D0*(DIG-3.0D0)
      RL = 1.2D0*DIG + 3.0D0
      SLAK = 3.0D0+4.0D0*(-DLOG10(TOL)-7.0D0)/11.0D0
      SLAK = DMAX1(SLAK,3.0D0)
      ERTOL = TOL*10.0D0**SLAK
      RM = 0.5D0*(ALIM + ELIM)
      RM = DMIN1(RM,200.0D0)
      RM = DMAX1(RM,RL+10.0D0)
      R2 = DMIN1(RM,FNUL)
C-----------------------------------------------------------------------
      WRITE (LUN,99999)
99999 FORMAT (' QUICK CHECK ROUTINE FOR THE J BESSEL FUNCTION FROM ZBESJ
     *'/)
      WRITE (LUN,99998)
99998 FORMAT (' PARAMETERS TOL,ELIM,ALIM,RL,FNUL,DIG')
      WRITE (LUN,99997) TOL, ELIM, ALIM, RL, FNUL, DIG
99997 FORMAT (6D12.4/)
      ATOL = 100.0D0*TOL
      HPI = 2.0D0*DATAN(1.0D0)
      PI = HPI + HPI
      CONR = 0.0D0
      CONI = -1.0D0/HPI
      WRITE (LUN,99996) MQC
99996 FORMAT (/' CHECKS IN THE (Z,FNU) SPACE WITH MQC = ',I2/)
C-----------------------------------------------------------------------
C     TEST VALUES OF Z IN -PI.LT.ARG(Z).LE.PI
C-----------------------------------------------------------------------
C-----------------------------------------------------------------------
C     KDO(K), K=1,IL  DETERMINES WHICH OF THE IL ANGLES IN -PI TO PI
C     ARE USE TO COMPUTE VALUES OF Z
C       KDO(K) = 0  MEANS THAT THE INDEX K WILL BE USED FOR ONE OR TWO
C                   VALUES OF Z, DEPENDING ON THE CHOICE OF KEPS(K)
C              = 1  MEANS THAT THE INDEX K AND THE CORRESPONDING ANGLE
C                   WILL BE SKIPPED
C     KEPS(K), K=1,IL DETERMINES WHICH OF THE ANGLES GET INCREMENTED
C     UP AND DOWN TO PUT VALUES OF Z IN REGIONS WHERE DIFFERENT
C     FORMULAE ARE USED.
C       KEPS(K) =0  MEANS THAT THE ANGLE WILL BE USED WITHOUT CHANGE
C               =1  MEANS THAT THE ANGLE WILL BE INCREMENTED UP AND
C                   DOWN BY EPS
C     THE ANGLES TO BE USED ARE STORED IN THE T(I) ARRAY, I=1,ITL
C-----------------------------------------------------------------------
      IF (MQC.NE.2) THEN
        NL=2
        IL=5
        DO 5 I=1,IL
          KEPS(I)=0
          KDO(I)=0
    5   CONTINUE
        NUL=5
        XNU(1) = 0.0D0
        XNU(2) = 1.0D0
        XNU(3) = 2.0D0
        XNU(4) = 0.5D0*FNUL
        XNU(5) = FNUL + 1.1D0
      ELSE
        NL=4
        IL=13
        DO 6 I=1,IL
          KDO(I)=0
          KEPS(I)=0
    6   CONTINUE
        KDO(2)=1
        KDO(6)=1
        KDO(8)=1
        KDO(12)=1
        KEPS(3)=1
        KEPS(4)=1
        KEPS(5)=1
        KEPS(9)=1
        KEPS(10)=1
        KEPS(11)=1
        NUL=6
        XNU(1) = 0.0D0
        XNU(2) = 0.6D0
        XNU(3) = 1.3D0
        XNU(4) = 2.0D0
        XNU(5) = 0.5D0*FNUL
        XNU(6) = FNUL + 1.1D0
      ENDIF
      I = 2
      EPS = 0.01D0
      FILM=DBLE(FLOAT(IL-1))
      T(1) = -PI + EPS
      DO 30 K=2,IL
        IF (KDO(K).EQ.0) THEN
          T(I) = PI*DBLE(FLOAT(-IL+2*K-1))/FILM
          IF (KEPS(K).EQ.0) GO TO 20
          TS=T(I)
          T(I) = TS - EPS
          I = I + 1
          T(I) = TS + EPS
   20     CONTINUE
          I = I + 1
        ENDIF
   30 CONTINUE
      ITL = I - 1
      LFLG = 0
      DO 260 KODE=1,2
        DO 250 N=1,NL
          NP = N+1
          DO 240 NU=1,NUL
            FNU = XNU(NU)
            GNU = FNU + DBLE(FLOAT(N-1)) + 1.0D0
            GNU = SQRT(GNU)
            GNU = MIN(GNU, 0.5D0*RL)
            DO 230 ICASE=1,3
              IRB = MIN0(2,ICASE)
              DO 220 IR=IRB,4
                GO TO (50, 60, 70), ICASE
   50           CONTINUE
                R = (GNU*DBLE(FLOAT(4-IR))+2.0D0*DBLE(FLOAT(IR-1)))/
     *           3.0D0
                GO TO 80
   60           CONTINUE
                R = (2.0D0*DBLE(FLOAT(4-IR))+R2*DBLE(FLOAT(IR-1)))/3.0D0
                GO TO 80
   70           CONTINUE
                IF (R2.GE.RM) GO TO 230
                R = (R2*DBLE(FLOAT(4-IR))+RM*DBLE(FLOAT(IR-1)))/3.0D0
   80           CONTINUE
                DO 210 IT=1,ITL
                  CT = COS(T(IT))
                  ST = SIN(T(IT))
                  IF (ABS(CT).LT.ATOL) CT = 0.0D0
                  IF (ABS(ST).LT.ATOL) ST = 0.0D0
                  ZR = R*CT
                  ZI = R*ST
                  IF(ZR.EQ.0.0.AND.ZI.EQ.0.0) GO TO 210
                  CALL ZDIV(CONR,CONI,ZR,ZI,WRR,WRI)
                  M=1
                  IF(ZI.LT.0.0) THEN
                    M=2
                    WRR = -WRR
                    WRI = -WRI
                  ENDIF
                  CALL ZBESJ(ZR,ZI,FNU,KODE,NP,CJR,CJI,NZJ,IERRJ)
                  CALL ZBESH(ZR,ZI,FNU,KODE,M,NP,CHR,CHI,NZH,IERRH)
                  IF(NZJ.NE.0.OR.NZH.NE.0) GO TO 210
                  IF(IERRJ.NE.0.OR.IERRH.NE.0) GO TO 210
                  IF(KODE.EQ.2) THEN
                    SGN = 3.0D0-2.0D0*DBLE(FLOAT(M))
                    STR = COS(ZR)
                    STI = -SGN*SIN(ZR)
                    T1R = WRR*STR - WRI*STI
                    WRI = WRR*STI + WRI*STR
                    WRR = T1R
                  ENDIF
                  KK = 0
                  MFLG = 0
                  DO 190 I=1,N
                    STR = CJR(I)*CHR(I+1) - CJI(I)*CHI(I+1)
                    T1I = CJR(I)*CHI(I+1) + CJI(I)*CHR(I+1)
                    T1R = STR
                    STR = CJR(I+1)*CHR(I) - CJI(I+1)*CHI(I)
                    T2I = CJR(I+1)*CHI(I) + CJI(I+1)*CHR(I)
                    T2R = STR
                    CERR = T1R - T2R -WRR
                    CERI = T1I - T2I -WRI
                    ER=ZABS(CERR,CERI)/ZABS(WRR,WRI)
                    IF (ER.GT.ERTOL) THEN
                      IF(MFLG.EQ.0) THEN
                        MFLG = 1
                        KK=I
                      ENDIF
                    ENDIF
                    AER(I)=ER
  190             CONTINUE
                  IF (MFLG.EQ.0) GO TO 210
                  IF (LFLG.EQ.1) GO TO 200
                  WRITE (LUN,99995) ERTOL
99995             FORMAT (/' CASES WHICH VIOLATE THE RELATIVE ERROR TEST
     * WITH ERTOL =', D12.4/)
                  WRITE (LUN,99994)
99994             FORMAT (/' OUTPUT FORMAT'/' KODE,N,IR,IT,NZJ,NZH,ICASE
     *')
                  WRITE (LUN,99993)
99993             FORMAT (' ER(K),K=1,N'/' Z,FNU,CJ(KK),CH(KK), KK=INDEX
     * OF FIRST NON-ZERO Y,W PAIR'/)
                  LFLG = 1
  200             CONTINUE
                  WRITE (LUN,99992) KODE, N, IR, IT, NZJ, NZH, ICASE
99992             FORMAT (8I5)
                  WRITE (LUN,99991) (AER(K),K=1,N)
                  WRITE (LUN,99991) ZR, ZI, FNU, CJR(KK), CJI(KK),
     *             CHR(KK), CHI(KK)
99991             FORMAT (9D12.4)
  210           CONTINUE
  220         CONTINUE
  230       CONTINUE
  240     CONTINUE
  250   CONTINUE
  260 CONTINUE
      IF (LFLG.EQ.0) WRITE (LUN,99990)
99990 FORMAT (/' QUICK CHECKS OK'/)
      STOP
      END
