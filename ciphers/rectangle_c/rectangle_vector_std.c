/* This code was generated by Usuba.
   See https://github.com/DadaIsCrazy/usuba.
   From the file "samples/usuba/rectangle_vector.ua" (included below). */

#include <stdint.h>

/* Do NOT change the order of those define/include */
#define NO_RUNTIME
#ifndef BITS_PER_REG
#define BITS_PER_REG 16
#endif
/* including the architecture specific .h */
#include "STD.h"

/* auxiliary functions */
void SubColumn__ (/*inputs*/ DATATYPE a0,DATATYPE a1,DATATYPE a2,DATATYPE a3, /*outputs*/ DATATYPE* b0,DATATYPE* b1,DATATYPE* b2,DATATYPE* b3) {
  
  // Variables declaration
  DATATYPE t1;
  DATATYPE t11;
  DATATYPE t2;
  DATATYPE t3;
  DATATYPE t5;
  DATATYPE t6;
  DATATYPE t8;
  DATATYPE t9;

  // Instructions (body)
  t1 = NOT(a1);
  t3 = XOR(a2,a3);
  t8 = XOR(a1,a2);
  t2 = AND(a0,t1);
  t5 = OR(a3,t1);
  *b0 = XOR(t2,t3);
  t6 = XOR(a0,t5);
  t11 = OR(*b0,t8);
  *b1 = XOR(a2,t6);
  t9 = AND(t3,t6);
  *b2 = XOR(t6,t11);
  *b3 = XOR(t8,t9);

}

/* main function */
void Rectangle__ (/*inputs*/ DATATYPE plain__[4],uint16_t key__[26][4], /*outputs*/ DATATYPE cipher__[4]) {
  
  // Variables declaration
  DATATYPE _tmp1_[4];
  DATATYPE tmp__[4];

  // Instructions (body)
  tmp__[0] = plain__[0];
  tmp__[1] = plain__[1];
  tmp__[2] = plain__[2];
  tmp__[3] = plain__[3];
  for (int i = 0; i <= 24; i++) {
    _tmp1_[0] = XOR(tmp__[0],LIFT_16(key__[i][0]));
    _tmp1_[1] = XOR(tmp__[1],LIFT_16(key__[i][1]));
    _tmp1_[2] = XOR(tmp__[2],LIFT_16(key__[i][2]));
    _tmp1_[3] = XOR(tmp__[3],LIFT_16(key__[i][3]));
    SubColumn__(_tmp1_[0],_tmp1_[1],_tmp1_[2],_tmp1_[3],&_tmp1_[0],&_tmp1_[1],&_tmp1_[2],&_tmp1_[3]);
    tmp__[0] = _tmp1_[0];
    tmp__[1] = L_ROTATE(_tmp1_[1],1,16);
    tmp__[2] = L_ROTATE(_tmp1_[2],12,16);
    tmp__[3] = L_ROTATE(_tmp1_[3],13,16);
  }
  cipher__[0] = XOR(tmp__[0],LIFT_16(key__[25][0]));
  cipher__[1] = XOR(tmp__[1],LIFT_16(key__[25][1]));
  cipher__[2] = XOR(tmp__[2],LIFT_16(key__[25][2]));
  cipher__[3] = XOR(tmp__[3],LIFT_16(key__[25][3]));

}


/* **************************************************************** */
/*                            Usuba source                          */
/*                                                                  */
/*

_no_inline table SubColumn(input :  u16x4 :: base)
  returns out :  u16x4 :: base
{
  6, 5, 12, 10, 1, 14, 7, 9, 11, 0, 3, 13, 8, 15, 4, 2
}


 node ShiftRows(input :  u16x4 :: base)
  returns out :  u16x4 :: base
vars

let
  (out[0]) = input[0];
  (out[1]) = (input[1] <<< 1);
  (out[2]) = (input[2] <<< 12);
  (out[3]) = (input[3] <<< 13)
tel

 node Rectangle(plain :  u16x4 :: base,key : const u16x4[26] :: base)
  returns cipher :  u16x4 :: base
vars
  tmp :  u16x4[26] :: base
let
  (tmp[0]) = plain;
  _no_unroll forall i in [0,24] {
    (tmp[(i + 1)]) = ShiftRows(SubColumn((tmp[i] ^ key[i])))
  };
  (cipher) = (tmp[25] ^ key[25])
tel

*/
 