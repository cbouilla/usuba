/* This code was generated by Usuba.
   See https://github.com/DadaIsCrazy/usuba.
   From the file "nist/drygascon/usuba/ua/drygascon.ua" (included below). */

#include <stdint.h>

/* Do NOT change the order of those define/include */

#ifndef BITS_PER_REG
#define BITS_PER_REG 64
#endif
/* including the architecture specific .h */
#include "MASKED.h"

/* auxiliary functions */
void Sbox__V64 (/*inputs*/ DATATYPE x[5][MASKING_ORDER], /*outputs*/ DATATYPE xr[5][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _shadow_t04_[MASKING_ORDER];
  DATATYPE _shadow_t15_[MASKING_ORDER];
  DATATYPE _shadow_t26_[MASKING_ORDER];
  DATATYPE _shadow_t37_[MASKING_ORDER];
  DATATYPE _shadow_t48_[MASKING_ORDER];
  DATATYPE _shadow_x015_[MASKING_ORDER];
  DATATYPE _shadow_x01_[MASKING_ORDER];
  DATATYPE _shadow_x09_[MASKING_ORDER];
  DATATYPE _shadow_x110_[MASKING_ORDER];
  DATATYPE _shadow_x114_[MASKING_ORDER];
  DATATYPE _shadow_x211_[MASKING_ORDER];
  DATATYPE _shadow_x217_[MASKING_ORDER];
  DATATYPE _shadow_x23_[MASKING_ORDER];
  DATATYPE _shadow_x312_[MASKING_ORDER];
  DATATYPE _shadow_x316_[MASKING_ORDER];
  DATATYPE _shadow_x413_[MASKING_ORDER];
  DATATYPE _shadow_x42_[MASKING_ORDER];
  DATATYPE t0[MASKING_ORDER];
  DATATYPE t1[MASKING_ORDER];
  DATATYPE t2[MASKING_ORDER];
  DATATYPE t3[MASKING_ORDER];
  DATATYPE t4[MASKING_ORDER];

  // Instructions (body)
  XOR(_shadow_x01_,x[0],x[4]);
  XOR(_shadow_x42_,x[4],x[3]);
  XOR(_shadow_x23_,x[2],x[1]);
  NOT(t0,_shadow_x01_);
  NOT(t1,x[1]);
  NOT(t2,_shadow_x23_);
  NOT(t3,x[3]);
  NOT(t4,_shadow_x42_);
  AND(_shadow_t04_,t0,x[1]);
  AND(_shadow_t15_,t1,_shadow_x23_);
  AND(_shadow_t26_,t2,x[3]);
  AND(_shadow_t37_,t3,_shadow_x42_);
  AND(_shadow_t48_,t4,_shadow_x01_);
  XOR(_shadow_x09_,_shadow_x01_,_shadow_t15_);
  XOR(_shadow_x110_,x[1],_shadow_t26_);
  XOR(_shadow_x211_,_shadow_x23_,_shadow_t37_);
  XOR(_shadow_x312_,x[3],_shadow_t48_);
  XOR(_shadow_x413_,_shadow_x42_,_shadow_t04_);
  XOR(_shadow_x114_,_shadow_x110_,_shadow_x09_);
  XOR(_shadow_x015_,_shadow_x09_,_shadow_x413_);
  XOR(_shadow_x316_,_shadow_x312_,_shadow_x211_);
  NOT(_shadow_x217_,_shadow_x211_);
  ASGN(xr[0],_shadow_x015_);
  ASGN(xr[1],_shadow_x114_);
  ASGN(xr[2],_shadow_x217_);
  ASGN(xr[3],_shadow_x316_);
  ASGN(xr[4],_shadow_x413_);

}

void AddConstant__V64 (/*inputs*/ DATATYPE state__[5][MASKING_ORDER],DATATYPE c__[MASKING_ORDER], /*outputs*/ DATATYPE stateR__[5][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _tmp1_[MASKING_ORDER];

  // Instructions (body)
  XOR(_tmp1_,state__[2],c__);
  ASGN(stateR__[0],state__[0]);
  ASGN(stateR__[1],state__[1]);
  ASGN(stateR__[2],_tmp1_);
  ASGN(stateR__[3],state__[3]);
  ASGN(stateR__[4],state__[4]);

}

void Rotr32__V_Natnat_64 (/*inputs*/ DATATYPE x__[MASKING_ORDER],unsigned int n__, /*outputs*/ DATATYPE y__[MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _tmp2_[MASKING_ORDER];
  DATATYPE _tmp3_[MASKING_ORDER];
  DATATYPE _tmp4_[MASKING_ORDER];
  DATATYPE _tmp75_[MASKING_ORDER];

  // Instructions (body)
  R_SHIFT(_tmp2_,x__,n__,64);
  L_SHIFT(_tmp3_,x__,(32 - n__),64);
  XOR(_tmp4_,_tmp2_,_tmp3_);
  ASGN_CST(_tmp75_, LIFT_64(4294967295));
  AND_CST(y__,_tmp4_,_tmp75_);

}

void BitRotR_odd__V_Natnat_64 (/*inputs*/ DATATYPE x__[MASKING_ORDER],unsigned int shift__, /*outputs*/ DATATYPE y__[MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _shadow_i1__18_[MASKING_ORDER];
  unsigned int _tmp12_;
  unsigned int _tmp14_;
  DATATYPE _tmp15_[MASKING_ORDER];
  DATATYPE _tmp17_[MASKING_ORDER];
  unsigned int _tmp8_;
  DATATYPE i0__[MASKING_ORDER];
  DATATYPE i1__[MASKING_ORDER];
  DATATYPE t__[MASKING_ORDER];
  DATATYPE _tmp77_[MASKING_ORDER];
  DATATYPE _tmp76_[MASKING_ORDER];

  // Instructions (body)
  ASGN_CST(_tmp76_, LIFT_64(4294967295));
  AND_CST(i0__,x__,_tmp76_);
  R_SHIFT(i1__,x__,32,64);
  _tmp8_ = ((shift__) / (2));
  Rotr32__V_Natnat_64(i1__,_tmp8_,t__);
  _tmp12_ = ((_tmp8_) + (1));
  _tmp14_ = ((_tmp12_) % (32));
  Rotr32__V_Natnat_64(i0__,_tmp14_,_shadow_i1__18_);
  L_SHIFT(_tmp15_,_shadow_i1__18_,32,64);
  ASGN_CST(_tmp77_, LIFT_64(4294967295));
  AND_CST(_tmp17_,t__,_tmp77_);
  XOR(y__,_tmp15_,_tmp17_);

}

void BitRotR_eve__V_Natnat_64 (/*inputs*/ DATATYPE x__[MASKING_ORDER],unsigned int shift__, /*outputs*/ DATATYPE y__[MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _shadow_i0__20_[MASKING_ORDER];
  DATATYPE _shadow_i1__21_[MASKING_ORDER];
  unsigned int _tmp20_;
  DATATYPE _tmp23_[MASKING_ORDER];
  DATATYPE _tmp25_[MASKING_ORDER];
  DATATYPE i0__[MASKING_ORDER];
  DATATYPE i1__[MASKING_ORDER];
  DATATYPE _tmp79_[MASKING_ORDER];
  DATATYPE _tmp78_[MASKING_ORDER];

  // Instructions (body)
  ASGN_CST(_tmp78_, LIFT_64(4294967295));
  AND_CST(i0__,x__,_tmp78_);
  R_SHIFT(i1__,x__,32,64);
  _tmp20_ = ((shift__) / (2));
  Rotr32__V_Natnat_64(i0__,_tmp20_,_shadow_i0__20_);
  Rotr32__V_Natnat_64(i1__,_tmp20_,_shadow_i1__21_);
  L_SHIFT(_tmp23_,_shadow_i1__21_,32,64);
  ASGN_CST(_tmp79_, LIFT_64(4294967295));
  AND_CST(_tmp25_,_shadow_i0__20_,_tmp79_);
  XOR(y__,_tmp23_,_tmp25_);

}

void LinearLayer__V64 (/*inputs*/ DATATYPE state__[5][MASKING_ORDER], /*outputs*/ DATATYPE stateR__[5][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _tmp27_[MASKING_ORDER];
  DATATYPE _tmp29_[MASKING_ORDER];
  DATATYPE _tmp30_[MASKING_ORDER];
  DATATYPE _tmp32_[MASKING_ORDER];
  DATATYPE _tmp34_[MASKING_ORDER];
  DATATYPE _tmp35_[MASKING_ORDER];
  DATATYPE _tmp37_[MASKING_ORDER];
  DATATYPE _tmp39_[MASKING_ORDER];
  DATATYPE _tmp40_[MASKING_ORDER];
  DATATYPE _tmp42_[MASKING_ORDER];
  DATATYPE _tmp44_[MASKING_ORDER];
  DATATYPE _tmp45_[MASKING_ORDER];
  DATATYPE _tmp47_[MASKING_ORDER];
  DATATYPE _tmp49_[MASKING_ORDER];
  DATATYPE _tmp50_[MASKING_ORDER];
  unsigned int _tmp89_;
  unsigned int _tmp88_;
  unsigned int _tmp87_;
  unsigned int _tmp86_;
  unsigned int _tmp85_;
  unsigned int _tmp84_;
  unsigned int _tmp83_;
  unsigned int _tmp82_;
  unsigned int _tmp81_;
  unsigned int _tmp80_;

  // Instructions (body)
  _tmp80_ = 19;
  BitRotR_odd__V_Natnat_64(state__[0],_tmp80_,_tmp27_);
  _tmp81_ = 28;
  BitRotR_eve__V_Natnat_64(state__[0],_tmp81_,_tmp29_);
  XOR(_tmp30_,_tmp27_,_tmp29_);
  XOR(stateR__[0],state__[0],_tmp30_);
  _tmp82_ = 61;
  BitRotR_odd__V_Natnat_64(state__[1],_tmp82_,_tmp32_);
  _tmp83_ = 38;
  BitRotR_eve__V_Natnat_64(state__[1],_tmp83_,_tmp34_);
  XOR(_tmp35_,_tmp32_,_tmp34_);
  XOR(stateR__[1],state__[1],_tmp35_);
  _tmp84_ = 1;
  BitRotR_odd__V_Natnat_64(state__[2],_tmp84_,_tmp37_);
  _tmp85_ = 6;
  BitRotR_eve__V_Natnat_64(state__[2],_tmp85_,_tmp39_);
  XOR(_tmp40_,_tmp37_,_tmp39_);
  XOR(stateR__[2],state__[2],_tmp40_);
  _tmp86_ = 10;
  BitRotR_eve__V_Natnat_64(state__[3],_tmp86_,_tmp42_);
  _tmp87_ = 17;
  BitRotR_odd__V_Natnat_64(state__[3],_tmp87_,_tmp44_);
  XOR(_tmp45_,_tmp42_,_tmp44_);
  XOR(stateR__[3],state__[3],_tmp45_);
  _tmp88_ = 7;
  BitRotR_odd__V_Natnat_64(state__[4],_tmp88_,_tmp47_);
  _tmp89_ = 40;
  BitRotR_eve__V_Natnat_64(state__[4],_tmp89_,_tmp49_);
  XOR(_tmp50_,_tmp47_,_tmp49_);
  XOR(stateR__[4],state__[4],_tmp50_);

}

void CoreRound__V64 (/*inputs*/ DATATYPE c__[5][MASKING_ORDER],DATATYPE cst__[MASKING_ORDER], /*outputs*/ DATATYPE cR__[5][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _tmp51_[5][MASKING_ORDER];
  DATATYPE _tmp52_[5][MASKING_ORDER];

  // Instructions (body)
  AddConstant__V64(c__,cst__,_tmp51_);
  Sbox__V64(_tmp51_,_tmp52_);
  LinearLayer__V64(_tmp52_,cR__);

}

void Accumulate__V64 (/*inputs*/ DATATYPE r__[2][MASKING_ORDER],DATATYPE c__[5][MASKING_ORDER], /*outputs*/ DATATYPE rR__[2][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _tmp53_[MASKING_ORDER];
  DATATYPE _tmp54_[MASKING_ORDER];
  DATATYPE _tmp55_[MASKING_ORDER];
  DATATYPE _tmp56_[MASKING_ORDER];
  DATATYPE _tmp57_[MASKING_ORDER];
  DATATYPE _tmp58_[MASKING_ORDER];
  DATATYPE _tmp59_[MASKING_ORDER];
  DATATYPE _tmp60_[MASKING_ORDER];

  // Instructions (body)
  XOR(_tmp53_,r__[0],c__[0]);
  R_SHIFT(_tmp54_,c__[2],32,64);
  XOR(_tmp55_,_tmp53_,_tmp54_);
  L_SHIFT(_tmp56_,c__[3],32,64);
  XOR(rR__[0],_tmp55_,_tmp56_);
  XOR(_tmp57_,r__[1],c__[1]);
  R_SHIFT(_tmp58_,c__[3],32,64);
  XOR(_tmp59_,_tmp57_,_tmp58_);
  L_SHIFT(_tmp60_,c__[2],32,64);
  XOR(rR__[1],_tmp59_,_tmp60_);

}

/* main function */
void drysponge_g__ (/*inputs*/ DATATYPE c__[5][MASKING_ORDER], /*outputs*/ DATATYPE cR__[5][MASKING_ORDER],DATATYPE r__[2][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE csts__[12][MASKING_ORDER];
  DATATYPE round_c__[5][MASKING_ORDER];
  DATATYPE round_r__[2][MASKING_ORDER];

  // Instructions (body)
  ASGN_CST(csts__[0], LIFT_64(240));
  ASGN_CST(csts__[1], LIFT_64(225));
  ASGN_CST(csts__[2], LIFT_64(210));
  ASGN_CST(csts__[3], LIFT_64(195));
  ASGN_CST(csts__[4], LIFT_64(180));
  ASGN_CST(csts__[5], LIFT_64(165));
  ASGN_CST(csts__[6], LIFT_64(150));
  ASGN_CST(csts__[7], LIFT_64(135));
  ASGN_CST(csts__[8], LIFT_64(120));
  ASGN_CST(csts__[9], LIFT_64(105));
  ASGN_CST(csts__[10], LIFT_64(90));
  ASGN_CST(csts__[11], LIFT_64(75));
  ASGN(round_c__[0],c__[0]);
  ASGN(round_c__[1],c__[1]);
  ASGN(round_c__[2],c__[2]);
  ASGN(round_c__[3],c__[3]);
  ASGN(round_c__[4],c__[4]);
  ASGN_CST(round_r__[0], LIFT_64(0));
  ASGN_CST(round_r__[1], LIFT_64(0));
  for (int i__ = 0; i__ <= 10; i__++) {
    CoreRound__V64(round_c__,csts__[i__],round_c__);
    Accumulate__V64(round_r__,round_c__,round_r__);
  }
  ASGN(cR__[0],round_c__[0]);
  ASGN(cR__[1],round_c__[1]);
  ASGN(cR__[2],round_c__[2]);
  ASGN(cR__[3],round_c__[3]);
  ASGN(cR__[4],round_c__[4]);
  ASGN(r__[0],round_r__[0]);
  ASGN(r__[1],round_r__[1]);

}

/* Additional functions */
uint32_t bench_speed() {
  /* inputs */
  DATATYPE c__[5][MASKING_ORDER] = { 0 };
  /* outputs */
  DATATYPE cR__[5][MASKING_ORDER] = { 0 };
  DATATYPE r__[2][MASKING_ORDER] = { 0 };
  /* fun call */
  drysponge_g__(c__,cR__, r__);

  /* Returning the number of encrypted bytes */
  return 56;
}

/* **************************************************************** */
/*                            Usuba source                          */
/*                                                                  */
/*

 table Sbox(x :  v5 :: base)
  returns y :  v5 :: base
{
  4, 11, 31, 20, 26, 21, 9, 2, 27, 5, 8, 18, 29, 3, 6, 28, 30, 19, 7, 14, 0, 13, 17, 24, 16, 12, 1, 25, 22, 10, 15, 23
}


 node AddConstant(state :  u64x5 :: base,c :  u64 :: base)
  returns stateR :  u64x5 :: base
vars

let
  (stateR) = (state[0,1],(state[2] ^ c),state[3,4])
tel

 node Rotr32(x :  u64 :: base,n :  nat :: base)
  returns y :  u64 :: base
vars

let
  (y) = (((x >> n) ^ (x << (32 - n))) & 4294967295)
tel

_inline node BitRotR_odd(x :  u64 :: base,shift :  nat :: base)
  returns y :  u64 :: base
vars
  i0 :  u64 :: base,
  i1 :  u64 :: base,
  t :  u64 :: base
let
  (i0) = (x & 4294967295);
  (i1) = (x >> 32);
  (t) = Rotr32(i1,(shift / 2));
  (i1) := Rotr32(i0,(((shift / 2) + 1) % 32));
  (i0) := t;
  (y) = ((i1 << 32) ^ (i0 & 4294967295))
tel

_inline node BitRotR_eve(x :  u64 :: base,shift :  nat :: base)
  returns y :  u64 :: base
vars
  i0 :  u64 :: base,
  i1 :  u64 :: base
let
  (i0) = (x & 4294967295);
  (i1) = (x >> 32);
  (i0) := Rotr32(i0,(shift / 2));
  (i1) := Rotr32(i1,(shift / 2));
  (y) = ((i1 << 32) ^ (i0 & 4294967295))
tel

 node LinearLayer(state :  u64x5 :: base)
  returns stateR :  u64x5 :: base
vars

let
  (stateR[0]) = (state[0] ^ (BitRotR_odd(state[0],19) ^ BitRotR_eve(state[0],28)));
  (stateR[1]) = (state[1] ^ (BitRotR_odd(state[1],61) ^ BitRotR_eve(state[1],38)));
  (stateR[2]) = (state[2] ^ (BitRotR_odd(state[2],1) ^ BitRotR_eve(state[2],6)));
  (stateR[3]) = (state[3] ^ (BitRotR_eve(state[3],10) ^ BitRotR_odd(state[3],17)));
  (stateR[4]) = (state[4] ^ (BitRotR_odd(state[4],7) ^ BitRotR_eve(state[4],40)))
tel

 node CoreRound(c :  u64x5 :: base,cst :  u64 :: base)
  returns cR :  u64x5 :: base
vars

let
  (cR) = LinearLayer(Sbox(AddConstant(c,cst)))
tel

 node Accumulate(r :  u64x2 :: base,c :  u64x5 :: base)
  returns rR :  u64x2 :: base
vars

let
  (rR[0]) = (((r[0] ^ c[0]) ^ (c[2] >> 32)) ^ (c[3] << 32));
  (rR[1]) = (((r[1] ^ c[1]) ^ (c[3] >> 32)) ^ (c[2] << 32))
tel

 node drysponge_g(c :  u64x5 :: base)
  returns cR :  u64x5 :: base,r :  u64x2 :: base
vars
  csts :  u64[12] :: base,
  round_c :  u64x5[12] :: base,
  round_r :  u64x2[12] :: base
let
  (csts) = (240,225,210,195,180,165,150,135,120,105,90,75);
  (round_c[0]) = c;
  (round_r[0]) = (0,0);
  forall i in [0,10] {
    (round_c[(i + 1)]) = CoreRound(round_c[i],csts[i]);
    (round_r[(i + 1)]) = Accumulate(round_r[i],round_c[(i + 1)])
  };
  (cR) = round_c[11];
  (r) = round_r[11]
tel

*/
 