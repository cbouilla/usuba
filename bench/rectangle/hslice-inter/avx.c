/* This code was generated by Usuba.
   See https://github.com/DadaIsCrazy/usuba.
   From the file "samples/usuba/rectangle.ua" (included below). */

#include <stdint.h>

/* Do NOT change the order of those define/include */

#ifndef BITS_PER_REG
#define BITS_PER_REG 256
#endif
/* including the architecture specific .h */
#include "AVX.h"

/* auxiliary functions */
void SubColumn__H16 (/*inputs*/ DATATYPE a0__,DATATYPE a0____2,DATATYPE a1__,DATATYPE a1____2,DATATYPE a2__,DATATYPE a2____2,DATATYPE a3__,DATATYPE a3____2, /*outputs*/ DATATYPE* b0__,DATATYPE* b0____2,DATATYPE* b1__,DATATYPE* b1____2,DATATYPE* b2__,DATATYPE* b2____2,DATATYPE* b3__,DATATYPE* b3____2) {

  // Variables declaration
  DATATYPE t1__;
  DATATYPE t1____2;
  DATATYPE t11__;
  DATATYPE t11____2;
  DATATYPE t2__;
  DATATYPE t2____2;
  DATATYPE t3__;
  DATATYPE t3____2;
  DATATYPE t5__;
  DATATYPE t5____2;
  DATATYPE t6__;
  DATATYPE t6____2;
  DATATYPE t8__;
  DATATYPE t8____2;
  DATATYPE t9__;
  DATATYPE t9____2;

  // Instructions (body)
  t1__ = NOT(a1__);
  t1____2 = NOT(a1____2);
  t3__ = XOR(a2__,a3__);
  t3____2 = XOR(a2____2,a3____2);
  t8__ = XOR(a1__,a2__);
  t8____2 = XOR(a1____2,a2____2);
  t2__ = AND(a0__,t1__);
  t5__ = OR(a3__,t1__);
  t2____2 = AND(a0____2,t1____2);
  t5____2 = OR(a3____2,t1____2);
  *b0__ = XOR(t2__,t3__);
  t6__ = XOR(a0__,t5__);
  *b0____2 = XOR(t2____2,t3____2);
  t6____2 = XOR(a0____2,t5____2);
  t11__ = OR(*b0__,t8__);
  *b1__ = XOR(a2__,t6__);
  t9__ = AND(t3__,t6__);
  t11____2 = OR(*b0____2,t8____2);
  *b1____2 = XOR(a2____2,t6____2);
  t9____2 = AND(t3____2,t6____2);
  *b2__ = XOR(t6__,t11__);
  *b3__ = XOR(t8__,t9__);
  *b2____2 = XOR(t6____2,t11____2);
  *b3____2 = XOR(t8____2,t9____2);

}

/* main function */
void Rectangle__ (/*inputs*/ DATATYPE plain__[4],DATATYPE plain____2[4],DATATYPE key__[26][4], /*outputs*/ DATATYPE cipher__[4],DATATYPE cipher____2[4]) {

  // Variables declaration
  DATATYPE _tmp1_[4];
  DATATYPE _tmp1___2[4];
  DATATYPE _tmp21_;
  DATATYPE _tmp21___2;
  DATATYPE _tmp22_;
  DATATYPE _tmp22___2;
  DATATYPE _tmp23_;
  DATATYPE _tmp23___2;
  DATATYPE _tmp24_;
  DATATYPE _tmp24___2;
  DATATYPE _tmp25_;
  DATATYPE _tmp25___2;
  DATATYPE _tmp26_;
  DATATYPE _tmp26___2;
  DATATYPE _tmp27_;
  DATATYPE _tmp27___2;
  DATATYPE _tmp28_;
  DATATYPE _tmp28___2;
  DATATYPE _tmp29_;
  DATATYPE _tmp29___2;
  DATATYPE _tmp2_[4];
  DATATYPE _tmp2___2[4];
  DATATYPE _tmp30_;
  DATATYPE _tmp30___2;
  DATATYPE _tmp31_;
  DATATYPE _tmp31___2;
  DATATYPE _tmp32_;
  DATATYPE _tmp32___2;
  DATATYPE _tmp33_;
  DATATYPE _tmp33___2;
  DATATYPE _tmp34_;
  DATATYPE _tmp34___2;
  DATATYPE _tmp35_;
  DATATYPE _tmp35___2;
  DATATYPE _tmp36_;
  DATATYPE _tmp36___2;
  DATATYPE _tmp37_;
  DATATYPE _tmp37___2;
  DATATYPE _tmp38_;
  DATATYPE _tmp38___2;
  DATATYPE tmp__[4];
  DATATYPE tmp____2[4];

  // Instructions (body)
  tmp__[0] = plain__[0];
  tmp__[1] = plain__[1];
  tmp____2[0] = plain____2[0];
  tmp____2[1] = plain____2[1];
  tmp__[2] = plain__[2];
  tmp__[3] = plain__[3];
  tmp____2[2] = plain____2[2];
  tmp____2[3] = plain____2[3];
  for (int i__ = 0; i__ <= 24; i__++) {
    _tmp1_[0] = XOR(tmp__[0],key__[i__][0]);
    _tmp1_[1] = XOR(tmp__[1],key__[i__][1]);
    _tmp1___2[0] = XOR(tmp____2[0],key__[i__][0]);
    _tmp1___2[1] = XOR(tmp____2[1],key__[i__][1]);
    _tmp1_[2] = XOR(tmp__[2],key__[i__][2]);
    _tmp1_[3] = XOR(tmp__[3],key__[i__][3]);
    _tmp1___2[2] = XOR(tmp____2[2],key__[i__][2]);
    _tmp1___2[3] = XOR(tmp____2[3],key__[i__][3]);
    SubColumn__H16(_tmp1_[0],_tmp1___2[0],_tmp1_[1],_tmp1___2[1],_tmp1_[2],_tmp1___2[2],_tmp1_[3],_tmp1___2[3],&_tmp2_[0],&_tmp2___2[0],&_tmp2_[1],&_tmp2___2[1],&_tmp2_[2],&_tmp2___2[2],&_tmp2_[3],&_tmp2___2[3]);
    tmp__[0] = _tmp2_[0];
    _tmp36_ = PERMUT_16(_tmp2_[1],1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0);
    tmp____2[0] = _tmp2___2[0];
    _tmp36___2 = PERMUT_16(_tmp2___2[1],1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0);
    _tmp37_ = PERMUT_16(_tmp2_[2],12,13,14,15,0,1,2,3,4,5,6,7,8,9,10,11);
    _tmp37___2 = PERMUT_16(_tmp2___2[2],12,13,14,15,0,1,2,3,4,5,6,7,8,9,10,11);
    _tmp38_ = PERMUT_16(_tmp2_[3],13,14,15,0,1,2,3,4,5,6,7,8,9,10,11,12);
    _tmp38___2 = PERMUT_16(_tmp2___2[3],13,14,15,0,1,2,3,4,5,6,7,8,9,10,11,12);
    _tmp33_ = _tmp36_;
    _tmp33___2 = _tmp36___2;
    _tmp34_ = _tmp37_;
    _tmp34___2 = _tmp37___2;
    _tmp35_ = _tmp38_;
    _tmp35___2 = _tmp38___2;
    _tmp30_ = _tmp33_;
    _tmp30___2 = _tmp33___2;
    _tmp31_ = _tmp34_;
    _tmp31___2 = _tmp34___2;
    _tmp32_ = _tmp35_;
    _tmp32___2 = _tmp35___2;
    _tmp27_ = _tmp30_;
    _tmp27___2 = _tmp30___2;
    _tmp28_ = _tmp31_;
    _tmp28___2 = _tmp31___2;
    _tmp29_ = _tmp32_;
    _tmp29___2 = _tmp32___2;
    _tmp24_ = _tmp27_;
    _tmp24___2 = _tmp27___2;
    _tmp25_ = _tmp28_;
    _tmp25___2 = _tmp28___2;
    _tmp26_ = _tmp29_;
    _tmp26___2 = _tmp29___2;
    _tmp21_ = _tmp24_;
    _tmp21___2 = _tmp24___2;
    _tmp22_ = _tmp25_;
    _tmp22___2 = _tmp25___2;
    _tmp23_ = _tmp26_;
    _tmp23___2 = _tmp26___2;
    tmp__[1] = _tmp21_;
    tmp____2[1] = _tmp21___2;
    tmp__[2] = _tmp22_;
    tmp____2[2] = _tmp22___2;
    tmp__[3] = _tmp23_;
    tmp____2[3] = _tmp23___2;
  }
  cipher__[0] = XOR(tmp__[0],key__[25][0]);
  cipher__[1] = XOR(tmp__[1],key__[25][1]);
  cipher____2[0] = XOR(tmp____2[0],key__[25][0]);
  cipher____2[1] = XOR(tmp____2[1],key__[25][1]);
  cipher__[2] = XOR(tmp__[2],key__[25][2]);
  cipher__[3] = XOR(tmp__[3],key__[25][3]);
  cipher____2[2] = XOR(tmp____2[2],key__[25][2]);
  cipher____2[3] = XOR(tmp____2[3],key__[25][3]);

}

/* Additional functions */


/* **************************************************************** */
/*                            Usuba source                          */
/*                                                                  */
/*

 table SubColumn(input :  v4)
  returns out :  v4
{
  6, 5, 12, 10, 1, 14, 7, 9, 11, 0, 3, 13, 8, 15, 4, 2
}


 node ShiftRows(input :  u16x4)
  returns out :  u16x4
vars

let
  (out[0]) = input[0];
  (out[1]) = (input[1] <<< 1);
  (out[2]) = (input[2] <<< 12);
  (out[3]) = (input[3] <<< 13)
tel

 node Rectangle(plain :  u16x4,key : const u16x4[26])
  returns cipher :  u16x4
vars
  tmp :  u16x4[26]
let
  (tmp[0]) = plain;
  forall i in [0,24] {
    (tmp[(i + 1)]) = ShiftRows(SubColumn((tmp[i] ^ key[i])))
  };
  (cipher) = (tmp[25] ^ key[25])
tel

*/
 