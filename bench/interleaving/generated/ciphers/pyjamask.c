/* This code was generated by Usuba.
   See https://github.com/DadaIsCrazy/usuba.
   From the file "samples/usuba/pyjamask.ua" (included below). */

#include <stdint.h>

/* Do NOT change the order of those define/include */

#ifndef BITS_PER_REG
#define BITS_PER_REG 32
#endif
/* including the architecture specific .h */
#include "STD.h"

/* auxiliary functions */
void SubBytes__V32 (/*inputs*/ DATATYPE s0__,DATATYPE s1__,DATATYPE s2__,DATATYPE s3__, /*outputs*/ DATATYPE ret__[4]) {

  // Variables declaration
  DATATYPE _shadow_s0__1_;
  DATATYPE _shadow_s1__4_;
  DATATYPE _shadow_s2__5_;
  DATATYPE _shadow_s3__2_;
  DATATYPE _tmp1_;
  DATATYPE _tmp2_;
  DATATYPE _tmp3_;
  DATATYPE _tmp4_;

  // Instructions (body)
  _shadow_s0__1_ = XOR(s0__,s3__);
  _tmp2_ = AND(s1__,s2__);
  _tmp1_ = AND(_shadow_s0__1_,s1__);
  ret__[0] = XOR(_shadow_s0__1_,_tmp2_);
  _shadow_s3__2_ = XOR(s3__,_tmp1_);
  _tmp3_ = AND(s2__,_shadow_s3__2_);
  _tmp4_ = AND(ret__[0],_shadow_s3__2_);
  ret__[2] = NOT(_shadow_s3__2_);
  _shadow_s1__4_ = XOR(s1__,_tmp3_);
  _shadow_s2__5_ = XOR(s2__,_tmp4_);
  ret__[1] = XOR(_shadow_s1__4_,ret__[0]);
  ret__[3] = XOR(_shadow_s2__5_,_shadow_s1__4_);

}

/* main function */
void pyjamask__ (/*inputs*/ DATATYPE plaintext__[4],DATATYPE key__[15][4], /*outputs*/ DATATYPE ciphertext__[4]) {

  // Variables declaration
  DATATYPE MixRows__V32_1_M__[4];
  DATATYPE MixRows__V32_1_mat_mult__V32_1__tmp5_;
  DATATYPE MixRows__V32_1_mat_mult__V32_1__tmp6_;
  DATATYPE MixRows__V32_1_mat_mult__V32_1_mask__;
  DATATYPE MixRows__V32_1_mat_mult__V32_1_mat_col__[33];
  DATATYPE MixRows__V32_1_mat_mult__V32_1_res_tmp__;
  DATATYPE _tmp11_[4];
  DATATYPE _tmp12_[4];
  DATATYPE round__[4];

  // Instructions (body)
  round__[0] = plaintext__[0];
  round__[1] = plaintext__[1];
  round__[2] = plaintext__[2];
  round__[3] = plaintext__[3];
  for (int i__ = 0; i__ <= 13; i__++) {
    _tmp11_[0] = XOR(round__[0],key__[i__][0]);
    _tmp11_[1] = XOR(round__[1],key__[i__][1]);
    _tmp11_[2] = XOR(round__[2],key__[i__][2]);
    _tmp11_[3] = XOR(round__[3],key__[i__][3]);
    MixRows__V32_1_M__[0] = LIFT_32(0xa3861085);
    MixRows__V32_1_M__[1] = LIFT_32(0x63417021);
    MixRows__V32_1_M__[2] = LIFT_32(0x692cf280);
    MixRows__V32_1_M__[3] = LIFT_32(0x48a54813);
    SubBytes__V32(_tmp11_[0],_tmp11_[1],_tmp11_[2],_tmp11_[3],_tmp12_);
    for (int i__2 = 0; i__2 <= 3; i__2++) {
      MixRows__V32_1_mat_mult__V32_1_mat_col__[0] = MixRows__V32_1_M__[i__2];
      MixRows__V32_1_mat_mult__V32_1_res_tmp__ = LIFT_32(0x0);
      for (int i__13 = 0; i__13 <= 31; i__13++) {
        MixRows__V32_1_mat_mult__V32_1__tmp5_ = L_SHIFT(_tmp12_[i__2],i__13,32);
        MixRows__V32_1_mat_mult__V32_1_mat_col__[(i__13 + 1)] = R_ROTATE(MixRows__V32_1_mat_mult__V32_1_mat_col__[i__13],1,32);
        MixRows__V32_1_mat_mult__V32_1_mask__ = RA_SHIFT(MixRows__V32_1_mat_mult__V32_1__tmp5_,31,32);
        MixRows__V32_1_mat_mult__V32_1__tmp6_ = AND(MixRows__V32_1_mat_mult__V32_1_mask__,MixRows__V32_1_mat_mult__V32_1_mat_col__[i__13]);
        MixRows__V32_1_mat_mult__V32_1_res_tmp__ = XOR(MixRows__V32_1_mat_mult__V32_1_res_tmp__,MixRows__V32_1_mat_mult__V32_1__tmp6_);
      }
      round__[i__2] = MixRows__V32_1_mat_mult__V32_1_res_tmp__;
    }
  }
  ciphertext__[0] = XOR(round__[0],key__[14][0]);
  ciphertext__[1] = XOR(round__[1],key__[14][1]);
  ciphertext__[2] = XOR(round__[2],key__[14][2]);
  ciphertext__[3] = XOR(round__[3],key__[14][3]);

}

/* Additional functions */
uint32_t bench_speed() {
  /* Inputs */
  DATATYPE plaintext__[4];
  DATATYPE key__[15][4];

  /* Preventing inputs from being optimized out */
  asm volatile("" : "+m" (plaintext__));
  asm volatile("" : "+m" (key__));

  /* Outputs */
  DATATYPE ciphertext__[4];
  /* Primitive call */
  pyjamask__(plaintext__, key__,ciphertext__);

  /* Preventing outputs from being optimized out */
  asm volatile("" : "+m" (ciphertext__));

  /* Returning the number of encrypted bytes */
  return 16;
}

/* **************************************************************** */
/*                            Usuba source                          */
/*                                                                  */
/*

 table SubBytes(i :  v4)
  returns o :  v4
{
  2, 13, 3, 9, 7, 11, 10, 6, 14, 0, 15, 4, 8, 5, 1, 12
}


 node AddRoundKey(i :  u32x4,k :  u32x4)
  returns o :  u32x4
vars

let
  (o) = (i ^ k)
tel

 node mat_mult(col :  u32,vec :  u32)
  returns res :  u32
vars
  mat_col :  u32[33],
  res_tmp :  u32[33],
  mask :  u32[32]
let
  (mat_col[0]) = col;
  (res_tmp[0]) = 0x0:u32;
  forall i in [0,31] {
    (mask[i]) = ((vec << i) >>! 31);
    (res_tmp[(i + 1)]) = (res_tmp[i] ^ (mask[i] & mat_col[i]));
    (mat_col[(i + 1)]) = (mat_col[i] >>> 1)
  };
  (res) = res_tmp[32]
tel

 node MixRows(input :  u32x4)
  returns output :  u32x4
vars
  M :  u32[4]
let
  (M) = (0xa3861085:u32,0x63417021:u32,0x692cf280:u32,0x48a54813:u32);
  forall i in [0,3] {
    (output[i]) = mat_mult(M[i],input[i])
  }
tel

 node pyjamask(plaintext :  u32x4,key :  u32x4[15])
  returns ciphertext :  u32x4
vars
  round :  u32x4[15]
let
  (round[0]) = plaintext;
  forall i in [0,13] {
    (round[(i + 1)]) = MixRows(SubBytes(AddRoundKey(round[i],key[i])))
  };
  (ciphertext) = AddRoundKey(round[14],key[14])
tel

*/
 