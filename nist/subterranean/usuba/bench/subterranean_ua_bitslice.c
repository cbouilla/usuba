/* This code was generated by Usuba.
   See https://github.com/DadaIsCrazy/usuba.
   From the file "nist/subterranean/usuba/ua/subterranean.ua" (included below). */

#include <stdint.h>

/* Do NOT change the order of those define/include */

#ifndef BITS_PER_REG
#define BITS_PER_REG 32
#endif
/* including the architecture specific .h */
#include "STD.h"

/* auxiliary functions */
void chi__B1 (/*inputs*/ DATATYPE state__[257], /*outputs*/ DATATYPE stateR__[257]) {

  // Variables declaration
  DATATYPE _tmp1_;
  DATATYPE _tmp2_;
  DATATYPE _tmp3_;
  DATATYPE _tmp5_;
  DATATYPE _tmp6_;
  DATATYPE _tmp8_;
  DATATYPE _tmp9_;

  // Instructions (body)
  for (int i__ = 0; i__ <= 254; i__++) {
    _tmp1_ = SET_ALL_ONE();
    _tmp2_ = XOR(_tmp1_,state__[(i__ + 1)]);
    _tmp3_ = AND(_tmp2_,state__[(i__ + 2)]);
    stateR__[i__] = XOR(state__[i__],_tmp3_);
  }
  _tmp5_ = NOT(state__[256]);
  _tmp6_ = AND(_tmp5_,state__[0]);
  stateR__[255] = XOR(state__[255],_tmp6_);
  _tmp8_ = NOT(state__[0]);
  _tmp9_ = AND(_tmp8_,state__[1]);
  stateR__[256] = XOR(state__[256],_tmp9_);

}

void iota__B1 (/*inputs*/ DATATYPE state__[257], /*outputs*/ DATATYPE stateR__[257]) {

  // Variables declaration
  ;

  // Instructions (body)
  stateR__[0] = NOT(state__[0]);
  for (int i__ = 1; i__ <= 256; i__++) {
    stateR__[i__] = state__[i__];
  }

}

void theta__B1 (/*inputs*/ DATATYPE state__[257], /*outputs*/ DATATYPE stateR__[257]) {

  // Variables declaration
  DATATYPE _tmp11_;

  // Instructions (body)
  for (int i__ = 0; i__ <= 256; i__++) {
    _tmp11_ = XOR(state__[i__],state__[((i__ + 3) % 257)]);
    stateR__[i__] = XOR(_tmp11_,state__[((i__ + 8) % 257)]);
  }

}

void round__B1 (/*inputs*/ DATATYPE state__[257], /*outputs*/ DATATYPE stateR__[257]) {

  // Variables declaration
  DATATYPE _tmp12_[257];
  DATATYPE _tmp13_[257];
  DATATYPE _tmp14_[257];

  // Instructions (body)
  chi__B1(state__,_tmp12_);
  iota__B1(_tmp12_,_tmp13_);
  theta__B1(_tmp13_,_tmp14_);
  stateR__[0] = _tmp14_[0];
  stateR__[1] = _tmp14_[12];
  stateR__[2] = _tmp14_[24];
  stateR__[3] = _tmp14_[36];
  stateR__[4] = _tmp14_[48];
  stateR__[5] = _tmp14_[60];
  stateR__[6] = _tmp14_[72];
  stateR__[7] = _tmp14_[84];
  stateR__[8] = _tmp14_[96];
  stateR__[9] = _tmp14_[108];
  stateR__[10] = _tmp14_[120];
  stateR__[11] = _tmp14_[132];
  stateR__[12] = _tmp14_[144];
  stateR__[13] = _tmp14_[156];
  stateR__[14] = _tmp14_[168];
  stateR__[15] = _tmp14_[180];
  stateR__[16] = _tmp14_[192];
  stateR__[17] = _tmp14_[204];
  stateR__[18] = _tmp14_[216];
  stateR__[19] = _tmp14_[228];
  stateR__[20] = _tmp14_[240];
  stateR__[21] = _tmp14_[252];
  stateR__[22] = _tmp14_[7];
  stateR__[23] = _tmp14_[19];
  stateR__[24] = _tmp14_[31];
  stateR__[25] = _tmp14_[43];
  stateR__[26] = _tmp14_[55];
  stateR__[27] = _tmp14_[67];
  stateR__[28] = _tmp14_[79];
  stateR__[29] = _tmp14_[91];
  stateR__[30] = _tmp14_[103];
  stateR__[31] = _tmp14_[115];
  stateR__[32] = _tmp14_[127];
  stateR__[33] = _tmp14_[139];
  stateR__[34] = _tmp14_[151];
  stateR__[35] = _tmp14_[163];
  stateR__[36] = _tmp14_[175];
  stateR__[37] = _tmp14_[187];
  stateR__[38] = _tmp14_[199];
  stateR__[39] = _tmp14_[211];
  stateR__[40] = _tmp14_[223];
  stateR__[41] = _tmp14_[235];
  stateR__[42] = _tmp14_[247];
  stateR__[43] = _tmp14_[2];
  stateR__[44] = _tmp14_[14];
  stateR__[45] = _tmp14_[26];
  stateR__[46] = _tmp14_[38];
  stateR__[47] = _tmp14_[50];
  stateR__[48] = _tmp14_[62];
  stateR__[49] = _tmp14_[74];
  stateR__[50] = _tmp14_[86];
  stateR__[51] = _tmp14_[98];
  stateR__[52] = _tmp14_[110];
  stateR__[53] = _tmp14_[122];
  stateR__[54] = _tmp14_[134];
  stateR__[55] = _tmp14_[146];
  stateR__[56] = _tmp14_[158];
  stateR__[57] = _tmp14_[170];
  stateR__[58] = _tmp14_[182];
  stateR__[59] = _tmp14_[194];
  stateR__[60] = _tmp14_[206];
  stateR__[61] = _tmp14_[218];
  stateR__[62] = _tmp14_[230];
  stateR__[63] = _tmp14_[242];
  stateR__[64] = _tmp14_[254];
  stateR__[65] = _tmp14_[9];
  stateR__[66] = _tmp14_[21];
  stateR__[67] = _tmp14_[33];
  stateR__[68] = _tmp14_[45];
  stateR__[69] = _tmp14_[57];
  stateR__[70] = _tmp14_[69];
  stateR__[71] = _tmp14_[81];
  stateR__[72] = _tmp14_[93];
  stateR__[73] = _tmp14_[105];
  stateR__[74] = _tmp14_[117];
  stateR__[75] = _tmp14_[129];
  stateR__[76] = _tmp14_[141];
  stateR__[77] = _tmp14_[153];
  stateR__[78] = _tmp14_[165];
  stateR__[79] = _tmp14_[177];
  stateR__[80] = _tmp14_[189];
  stateR__[81] = _tmp14_[201];
  stateR__[82] = _tmp14_[213];
  stateR__[83] = _tmp14_[225];
  stateR__[84] = _tmp14_[237];
  stateR__[85] = _tmp14_[249];
  stateR__[86] = _tmp14_[4];
  stateR__[87] = _tmp14_[16];
  stateR__[88] = _tmp14_[28];
  stateR__[89] = _tmp14_[40];
  stateR__[90] = _tmp14_[52];
  stateR__[91] = _tmp14_[64];
  stateR__[92] = _tmp14_[76];
  stateR__[93] = _tmp14_[88];
  stateR__[94] = _tmp14_[100];
  stateR__[95] = _tmp14_[112];
  stateR__[96] = _tmp14_[124];
  stateR__[97] = _tmp14_[136];
  stateR__[98] = _tmp14_[148];
  stateR__[99] = _tmp14_[160];
  stateR__[100] = _tmp14_[172];
  stateR__[101] = _tmp14_[184];
  stateR__[102] = _tmp14_[196];
  stateR__[103] = _tmp14_[208];
  stateR__[104] = _tmp14_[220];
  stateR__[105] = _tmp14_[232];
  stateR__[106] = _tmp14_[244];
  stateR__[107] = _tmp14_[256];
  stateR__[108] = _tmp14_[11];
  stateR__[109] = _tmp14_[23];
  stateR__[110] = _tmp14_[35];
  stateR__[111] = _tmp14_[47];
  stateR__[112] = _tmp14_[59];
  stateR__[113] = _tmp14_[71];
  stateR__[114] = _tmp14_[83];
  stateR__[115] = _tmp14_[95];
  stateR__[116] = _tmp14_[107];
  stateR__[117] = _tmp14_[119];
  stateR__[118] = _tmp14_[131];
  stateR__[119] = _tmp14_[143];
  stateR__[120] = _tmp14_[155];
  stateR__[121] = _tmp14_[167];
  stateR__[122] = _tmp14_[179];
  stateR__[123] = _tmp14_[191];
  stateR__[124] = _tmp14_[203];
  stateR__[125] = _tmp14_[215];
  stateR__[126] = _tmp14_[227];
  stateR__[127] = _tmp14_[239];
  stateR__[128] = _tmp14_[251];
  stateR__[129] = _tmp14_[6];
  stateR__[130] = _tmp14_[18];
  stateR__[131] = _tmp14_[30];
  stateR__[132] = _tmp14_[42];
  stateR__[133] = _tmp14_[54];
  stateR__[134] = _tmp14_[66];
  stateR__[135] = _tmp14_[78];
  stateR__[136] = _tmp14_[90];
  stateR__[137] = _tmp14_[102];
  stateR__[138] = _tmp14_[114];
  stateR__[139] = _tmp14_[126];
  stateR__[140] = _tmp14_[138];
  stateR__[141] = _tmp14_[150];
  stateR__[142] = _tmp14_[162];
  stateR__[143] = _tmp14_[174];
  stateR__[144] = _tmp14_[186];
  stateR__[145] = _tmp14_[198];
  stateR__[146] = _tmp14_[210];
  stateR__[147] = _tmp14_[222];
  stateR__[148] = _tmp14_[234];
  stateR__[149] = _tmp14_[246];
  stateR__[150] = _tmp14_[1];
  stateR__[151] = _tmp14_[13];
  stateR__[152] = _tmp14_[25];
  stateR__[153] = _tmp14_[37];
  stateR__[154] = _tmp14_[49];
  stateR__[155] = _tmp14_[61];
  stateR__[156] = _tmp14_[73];
  stateR__[157] = _tmp14_[85];
  stateR__[158] = _tmp14_[97];
  stateR__[159] = _tmp14_[109];
  stateR__[160] = _tmp14_[121];
  stateR__[161] = _tmp14_[133];
  stateR__[162] = _tmp14_[145];
  stateR__[163] = _tmp14_[157];
  stateR__[164] = _tmp14_[169];
  stateR__[165] = _tmp14_[181];
  stateR__[166] = _tmp14_[193];
  stateR__[167] = _tmp14_[205];
  stateR__[168] = _tmp14_[217];
  stateR__[169] = _tmp14_[229];
  stateR__[170] = _tmp14_[241];
  stateR__[171] = _tmp14_[253];
  stateR__[172] = _tmp14_[8];
  stateR__[173] = _tmp14_[20];
  stateR__[174] = _tmp14_[32];
  stateR__[175] = _tmp14_[44];
  stateR__[176] = _tmp14_[56];
  stateR__[177] = _tmp14_[68];
  stateR__[178] = _tmp14_[80];
  stateR__[179] = _tmp14_[92];
  stateR__[180] = _tmp14_[104];
  stateR__[181] = _tmp14_[116];
  stateR__[182] = _tmp14_[128];
  stateR__[183] = _tmp14_[140];
  stateR__[184] = _tmp14_[152];
  stateR__[185] = _tmp14_[164];
  stateR__[186] = _tmp14_[176];
  stateR__[187] = _tmp14_[188];
  stateR__[188] = _tmp14_[200];
  stateR__[189] = _tmp14_[212];
  stateR__[190] = _tmp14_[224];
  stateR__[191] = _tmp14_[236];
  stateR__[192] = _tmp14_[248];
  stateR__[193] = _tmp14_[3];
  stateR__[194] = _tmp14_[15];
  stateR__[195] = _tmp14_[27];
  stateR__[196] = _tmp14_[39];
  stateR__[197] = _tmp14_[51];
  stateR__[198] = _tmp14_[63];
  stateR__[199] = _tmp14_[75];
  stateR__[200] = _tmp14_[87];
  stateR__[201] = _tmp14_[99];
  stateR__[202] = _tmp14_[111];
  stateR__[203] = _tmp14_[123];
  stateR__[204] = _tmp14_[135];
  stateR__[205] = _tmp14_[147];
  stateR__[206] = _tmp14_[159];
  stateR__[207] = _tmp14_[171];
  stateR__[208] = _tmp14_[183];
  stateR__[209] = _tmp14_[195];
  stateR__[210] = _tmp14_[207];
  stateR__[211] = _tmp14_[219];
  stateR__[212] = _tmp14_[231];
  stateR__[213] = _tmp14_[243];
  stateR__[214] = _tmp14_[255];
  stateR__[215] = _tmp14_[10];
  stateR__[216] = _tmp14_[22];
  stateR__[217] = _tmp14_[34];
  stateR__[218] = _tmp14_[46];
  stateR__[219] = _tmp14_[58];
  stateR__[220] = _tmp14_[70];
  stateR__[221] = _tmp14_[82];
  stateR__[222] = _tmp14_[94];
  stateR__[223] = _tmp14_[106];
  stateR__[224] = _tmp14_[118];
  stateR__[225] = _tmp14_[130];
  stateR__[226] = _tmp14_[142];
  stateR__[227] = _tmp14_[154];
  stateR__[228] = _tmp14_[166];
  stateR__[229] = _tmp14_[178];
  stateR__[230] = _tmp14_[190];
  stateR__[231] = _tmp14_[202];
  stateR__[232] = _tmp14_[214];
  stateR__[233] = _tmp14_[226];
  stateR__[234] = _tmp14_[238];
  stateR__[235] = _tmp14_[250];
  stateR__[236] = _tmp14_[5];
  stateR__[237] = _tmp14_[17];
  stateR__[238] = _tmp14_[29];
  stateR__[239] = _tmp14_[41];
  stateR__[240] = _tmp14_[53];
  stateR__[241] = _tmp14_[65];
  stateR__[242] = _tmp14_[77];
  stateR__[243] = _tmp14_[89];
  stateR__[244] = _tmp14_[101];
  stateR__[245] = _tmp14_[113];
  stateR__[246] = _tmp14_[125];
  stateR__[247] = _tmp14_[137];
  stateR__[248] = _tmp14_[149];
  stateR__[249] = _tmp14_[161];
  stateR__[250] = _tmp14_[173];
  stateR__[251] = _tmp14_[185];
  stateR__[252] = _tmp14_[197];
  stateR__[253] = _tmp14_[209];
  stateR__[254] = _tmp14_[221];
  stateR__[255] = _tmp14_[233];
  stateR__[256] = _tmp14_[245];

}

void xor1__B1 (/*inputs*/ DATATYPE state__[257], /*outputs*/ DATATYPE stateR__[257]) {

  // Variables declaration
  ;

  // Instructions (body)
  stateR__[0] = state__[0];
  stateR__[1] = NOT(state__[1]);
  for (int i__ = 2; i__ <= 256; i__++) {
    stateR__[i__] = state__[i__];
  }

}

/* main function */
void blank__ (/*inputs*/ DATATYPE state__[257], /*outputs*/ DATATYPE stateR__[257]) {

  // Variables declaration
  DATATYPE _tmp16_[257];
  DATATYPE tmp__[257];

  // Instructions (body)
  tmp__[0] = state__[0];
  tmp__[1] = state__[1];
  tmp__[2] = state__[2];
  tmp__[3] = state__[3];
  tmp__[4] = state__[4];
  tmp__[5] = state__[5];
  tmp__[6] = state__[6];
  tmp__[7] = state__[7];
  tmp__[8] = state__[8];
  tmp__[9] = state__[9];
  tmp__[10] = state__[10];
  tmp__[11] = state__[11];
  tmp__[12] = state__[12];
  tmp__[13] = state__[13];
  tmp__[14] = state__[14];
  tmp__[15] = state__[15];
  tmp__[16] = state__[16];
  tmp__[17] = state__[17];
  tmp__[18] = state__[18];
  tmp__[19] = state__[19];
  tmp__[20] = state__[20];
  tmp__[21] = state__[21];
  tmp__[22] = state__[22];
  tmp__[23] = state__[23];
  tmp__[24] = state__[24];
  tmp__[25] = state__[25];
  tmp__[26] = state__[26];
  tmp__[27] = state__[27];
  tmp__[28] = state__[28];
  tmp__[29] = state__[29];
  tmp__[30] = state__[30];
  tmp__[31] = state__[31];
  tmp__[32] = state__[32];
  tmp__[33] = state__[33];
  tmp__[34] = state__[34];
  tmp__[35] = state__[35];
  tmp__[36] = state__[36];
  tmp__[37] = state__[37];
  tmp__[38] = state__[38];
  tmp__[39] = state__[39];
  tmp__[40] = state__[40];
  tmp__[41] = state__[41];
  tmp__[42] = state__[42];
  tmp__[43] = state__[43];
  tmp__[44] = state__[44];
  tmp__[45] = state__[45];
  tmp__[46] = state__[46];
  tmp__[47] = state__[47];
  tmp__[48] = state__[48];
  tmp__[49] = state__[49];
  tmp__[50] = state__[50];
  tmp__[51] = state__[51];
  tmp__[52] = state__[52];
  tmp__[53] = state__[53];
  tmp__[54] = state__[54];
  tmp__[55] = state__[55];
  tmp__[56] = state__[56];
  tmp__[57] = state__[57];
  tmp__[58] = state__[58];
  tmp__[59] = state__[59];
  tmp__[60] = state__[60];
  tmp__[61] = state__[61];
  tmp__[62] = state__[62];
  tmp__[63] = state__[63];
  tmp__[64] = state__[64];
  tmp__[65] = state__[65];
  tmp__[66] = state__[66];
  tmp__[67] = state__[67];
  tmp__[68] = state__[68];
  tmp__[69] = state__[69];
  tmp__[70] = state__[70];
  tmp__[71] = state__[71];
  tmp__[72] = state__[72];
  tmp__[73] = state__[73];
  tmp__[74] = state__[74];
  tmp__[75] = state__[75];
  tmp__[76] = state__[76];
  tmp__[77] = state__[77];
  tmp__[78] = state__[78];
  tmp__[79] = state__[79];
  tmp__[80] = state__[80];
  tmp__[81] = state__[81];
  tmp__[82] = state__[82];
  tmp__[83] = state__[83];
  tmp__[84] = state__[84];
  tmp__[85] = state__[85];
  tmp__[86] = state__[86];
  tmp__[87] = state__[87];
  tmp__[88] = state__[88];
  tmp__[89] = state__[89];
  tmp__[90] = state__[90];
  tmp__[91] = state__[91];
  tmp__[92] = state__[92];
  tmp__[93] = state__[93];
  tmp__[94] = state__[94];
  tmp__[95] = state__[95];
  tmp__[96] = state__[96];
  tmp__[97] = state__[97];
  tmp__[98] = state__[98];
  tmp__[99] = state__[99];
  tmp__[100] = state__[100];
  tmp__[101] = state__[101];
  tmp__[102] = state__[102];
  tmp__[103] = state__[103];
  tmp__[104] = state__[104];
  tmp__[105] = state__[105];
  tmp__[106] = state__[106];
  tmp__[107] = state__[107];
  tmp__[108] = state__[108];
  tmp__[109] = state__[109];
  tmp__[110] = state__[110];
  tmp__[111] = state__[111];
  tmp__[112] = state__[112];
  tmp__[113] = state__[113];
  tmp__[114] = state__[114];
  tmp__[115] = state__[115];
  tmp__[116] = state__[116];
  tmp__[117] = state__[117];
  tmp__[118] = state__[118];
  tmp__[119] = state__[119];
  tmp__[120] = state__[120];
  tmp__[121] = state__[121];
  tmp__[122] = state__[122];
  tmp__[123] = state__[123];
  tmp__[124] = state__[124];
  tmp__[125] = state__[125];
  tmp__[126] = state__[126];
  tmp__[127] = state__[127];
  tmp__[128] = state__[128];
  tmp__[129] = state__[129];
  tmp__[130] = state__[130];
  tmp__[131] = state__[131];
  tmp__[132] = state__[132];
  tmp__[133] = state__[133];
  tmp__[134] = state__[134];
  tmp__[135] = state__[135];
  tmp__[136] = state__[136];
  tmp__[137] = state__[137];
  tmp__[138] = state__[138];
  tmp__[139] = state__[139];
  tmp__[140] = state__[140];
  tmp__[141] = state__[141];
  tmp__[142] = state__[142];
  tmp__[143] = state__[143];
  tmp__[144] = state__[144];
  tmp__[145] = state__[145];
  tmp__[146] = state__[146];
  tmp__[147] = state__[147];
  tmp__[148] = state__[148];
  tmp__[149] = state__[149];
  tmp__[150] = state__[150];
  tmp__[151] = state__[151];
  tmp__[152] = state__[152];
  tmp__[153] = state__[153];
  tmp__[154] = state__[154];
  tmp__[155] = state__[155];
  tmp__[156] = state__[156];
  tmp__[157] = state__[157];
  tmp__[158] = state__[158];
  tmp__[159] = state__[159];
  tmp__[160] = state__[160];
  tmp__[161] = state__[161];
  tmp__[162] = state__[162];
  tmp__[163] = state__[163];
  tmp__[164] = state__[164];
  tmp__[165] = state__[165];
  tmp__[166] = state__[166];
  tmp__[167] = state__[167];
  tmp__[168] = state__[168];
  tmp__[169] = state__[169];
  tmp__[170] = state__[170];
  tmp__[171] = state__[171];
  tmp__[172] = state__[172];
  tmp__[173] = state__[173];
  tmp__[174] = state__[174];
  tmp__[175] = state__[175];
  tmp__[176] = state__[176];
  tmp__[177] = state__[177];
  tmp__[178] = state__[178];
  tmp__[179] = state__[179];
  tmp__[180] = state__[180];
  tmp__[181] = state__[181];
  tmp__[182] = state__[182];
  tmp__[183] = state__[183];
  tmp__[184] = state__[184];
  tmp__[185] = state__[185];
  tmp__[186] = state__[186];
  tmp__[187] = state__[187];
  tmp__[188] = state__[188];
  tmp__[189] = state__[189];
  tmp__[190] = state__[190];
  tmp__[191] = state__[191];
  tmp__[192] = state__[192];
  tmp__[193] = state__[193];
  tmp__[194] = state__[194];
  tmp__[195] = state__[195];
  tmp__[196] = state__[196];
  tmp__[197] = state__[197];
  tmp__[198] = state__[198];
  tmp__[199] = state__[199];
  tmp__[200] = state__[200];
  tmp__[201] = state__[201];
  tmp__[202] = state__[202];
  tmp__[203] = state__[203];
  tmp__[204] = state__[204];
  tmp__[205] = state__[205];
  tmp__[206] = state__[206];
  tmp__[207] = state__[207];
  tmp__[208] = state__[208];
  tmp__[209] = state__[209];
  tmp__[210] = state__[210];
  tmp__[211] = state__[211];
  tmp__[212] = state__[212];
  tmp__[213] = state__[213];
  tmp__[214] = state__[214];
  tmp__[215] = state__[215];
  tmp__[216] = state__[216];
  tmp__[217] = state__[217];
  tmp__[218] = state__[218];
  tmp__[219] = state__[219];
  tmp__[220] = state__[220];
  tmp__[221] = state__[221];
  tmp__[222] = state__[222];
  tmp__[223] = state__[223];
  tmp__[224] = state__[224];
  tmp__[225] = state__[225];
  tmp__[226] = state__[226];
  tmp__[227] = state__[227];
  tmp__[228] = state__[228];
  tmp__[229] = state__[229];
  tmp__[230] = state__[230];
  tmp__[231] = state__[231];
  tmp__[232] = state__[232];
  tmp__[233] = state__[233];
  tmp__[234] = state__[234];
  tmp__[235] = state__[235];
  tmp__[236] = state__[236];
  tmp__[237] = state__[237];
  tmp__[238] = state__[238];
  tmp__[239] = state__[239];
  tmp__[240] = state__[240];
  tmp__[241] = state__[241];
  tmp__[242] = state__[242];
  tmp__[243] = state__[243];
  tmp__[244] = state__[244];
  tmp__[245] = state__[245];
  tmp__[246] = state__[246];
  tmp__[247] = state__[247];
  tmp__[248] = state__[248];
  tmp__[249] = state__[249];
  tmp__[250] = state__[250];
  tmp__[251] = state__[251];
  tmp__[252] = state__[252];
  tmp__[253] = state__[253];
  tmp__[254] = state__[254];
  tmp__[255] = state__[255];
  tmp__[256] = state__[256];
  for (int i__ = 0; i__ <= 7; i__++) {
    round__B1(tmp__,_tmp16_);
    xor1__B1(_tmp16_,tmp__);
  }
  stateR__[0] = tmp__[0];
  stateR__[1] = tmp__[1];
  stateR__[2] = tmp__[2];
  stateR__[3] = tmp__[3];
  stateR__[4] = tmp__[4];
  stateR__[5] = tmp__[5];
  stateR__[6] = tmp__[6];
  stateR__[7] = tmp__[7];
  stateR__[8] = tmp__[8];
  stateR__[9] = tmp__[9];
  stateR__[10] = tmp__[10];
  stateR__[11] = tmp__[11];
  stateR__[12] = tmp__[12];
  stateR__[13] = tmp__[13];
  stateR__[14] = tmp__[14];
  stateR__[15] = tmp__[15];
  stateR__[16] = tmp__[16];
  stateR__[17] = tmp__[17];
  stateR__[18] = tmp__[18];
  stateR__[19] = tmp__[19];
  stateR__[20] = tmp__[20];
  stateR__[21] = tmp__[21];
  stateR__[22] = tmp__[22];
  stateR__[23] = tmp__[23];
  stateR__[24] = tmp__[24];
  stateR__[25] = tmp__[25];
  stateR__[26] = tmp__[26];
  stateR__[27] = tmp__[27];
  stateR__[28] = tmp__[28];
  stateR__[29] = tmp__[29];
  stateR__[30] = tmp__[30];
  stateR__[31] = tmp__[31];
  stateR__[32] = tmp__[32];
  stateR__[33] = tmp__[33];
  stateR__[34] = tmp__[34];
  stateR__[35] = tmp__[35];
  stateR__[36] = tmp__[36];
  stateR__[37] = tmp__[37];
  stateR__[38] = tmp__[38];
  stateR__[39] = tmp__[39];
  stateR__[40] = tmp__[40];
  stateR__[41] = tmp__[41];
  stateR__[42] = tmp__[42];
  stateR__[43] = tmp__[43];
  stateR__[44] = tmp__[44];
  stateR__[45] = tmp__[45];
  stateR__[46] = tmp__[46];
  stateR__[47] = tmp__[47];
  stateR__[48] = tmp__[48];
  stateR__[49] = tmp__[49];
  stateR__[50] = tmp__[50];
  stateR__[51] = tmp__[51];
  stateR__[52] = tmp__[52];
  stateR__[53] = tmp__[53];
  stateR__[54] = tmp__[54];
  stateR__[55] = tmp__[55];
  stateR__[56] = tmp__[56];
  stateR__[57] = tmp__[57];
  stateR__[58] = tmp__[58];
  stateR__[59] = tmp__[59];
  stateR__[60] = tmp__[60];
  stateR__[61] = tmp__[61];
  stateR__[62] = tmp__[62];
  stateR__[63] = tmp__[63];
  stateR__[64] = tmp__[64];
  stateR__[65] = tmp__[65];
  stateR__[66] = tmp__[66];
  stateR__[67] = tmp__[67];
  stateR__[68] = tmp__[68];
  stateR__[69] = tmp__[69];
  stateR__[70] = tmp__[70];
  stateR__[71] = tmp__[71];
  stateR__[72] = tmp__[72];
  stateR__[73] = tmp__[73];
  stateR__[74] = tmp__[74];
  stateR__[75] = tmp__[75];
  stateR__[76] = tmp__[76];
  stateR__[77] = tmp__[77];
  stateR__[78] = tmp__[78];
  stateR__[79] = tmp__[79];
  stateR__[80] = tmp__[80];
  stateR__[81] = tmp__[81];
  stateR__[82] = tmp__[82];
  stateR__[83] = tmp__[83];
  stateR__[84] = tmp__[84];
  stateR__[85] = tmp__[85];
  stateR__[86] = tmp__[86];
  stateR__[87] = tmp__[87];
  stateR__[88] = tmp__[88];
  stateR__[89] = tmp__[89];
  stateR__[90] = tmp__[90];
  stateR__[91] = tmp__[91];
  stateR__[92] = tmp__[92];
  stateR__[93] = tmp__[93];
  stateR__[94] = tmp__[94];
  stateR__[95] = tmp__[95];
  stateR__[96] = tmp__[96];
  stateR__[97] = tmp__[97];
  stateR__[98] = tmp__[98];
  stateR__[99] = tmp__[99];
  stateR__[100] = tmp__[100];
  stateR__[101] = tmp__[101];
  stateR__[102] = tmp__[102];
  stateR__[103] = tmp__[103];
  stateR__[104] = tmp__[104];
  stateR__[105] = tmp__[105];
  stateR__[106] = tmp__[106];
  stateR__[107] = tmp__[107];
  stateR__[108] = tmp__[108];
  stateR__[109] = tmp__[109];
  stateR__[110] = tmp__[110];
  stateR__[111] = tmp__[111];
  stateR__[112] = tmp__[112];
  stateR__[113] = tmp__[113];
  stateR__[114] = tmp__[114];
  stateR__[115] = tmp__[115];
  stateR__[116] = tmp__[116];
  stateR__[117] = tmp__[117];
  stateR__[118] = tmp__[118];
  stateR__[119] = tmp__[119];
  stateR__[120] = tmp__[120];
  stateR__[121] = tmp__[121];
  stateR__[122] = tmp__[122];
  stateR__[123] = tmp__[123];
  stateR__[124] = tmp__[124];
  stateR__[125] = tmp__[125];
  stateR__[126] = tmp__[126];
  stateR__[127] = tmp__[127];
  stateR__[128] = tmp__[128];
  stateR__[129] = tmp__[129];
  stateR__[130] = tmp__[130];
  stateR__[131] = tmp__[131];
  stateR__[132] = tmp__[132];
  stateR__[133] = tmp__[133];
  stateR__[134] = tmp__[134];
  stateR__[135] = tmp__[135];
  stateR__[136] = tmp__[136];
  stateR__[137] = tmp__[137];
  stateR__[138] = tmp__[138];
  stateR__[139] = tmp__[139];
  stateR__[140] = tmp__[140];
  stateR__[141] = tmp__[141];
  stateR__[142] = tmp__[142];
  stateR__[143] = tmp__[143];
  stateR__[144] = tmp__[144];
  stateR__[145] = tmp__[145];
  stateR__[146] = tmp__[146];
  stateR__[147] = tmp__[147];
  stateR__[148] = tmp__[148];
  stateR__[149] = tmp__[149];
  stateR__[150] = tmp__[150];
  stateR__[151] = tmp__[151];
  stateR__[152] = tmp__[152];
  stateR__[153] = tmp__[153];
  stateR__[154] = tmp__[154];
  stateR__[155] = tmp__[155];
  stateR__[156] = tmp__[156];
  stateR__[157] = tmp__[157];
  stateR__[158] = tmp__[158];
  stateR__[159] = tmp__[159];
  stateR__[160] = tmp__[160];
  stateR__[161] = tmp__[161];
  stateR__[162] = tmp__[162];
  stateR__[163] = tmp__[163];
  stateR__[164] = tmp__[164];
  stateR__[165] = tmp__[165];
  stateR__[166] = tmp__[166];
  stateR__[167] = tmp__[167];
  stateR__[168] = tmp__[168];
  stateR__[169] = tmp__[169];
  stateR__[170] = tmp__[170];
  stateR__[171] = tmp__[171];
  stateR__[172] = tmp__[172];
  stateR__[173] = tmp__[173];
  stateR__[174] = tmp__[174];
  stateR__[175] = tmp__[175];
  stateR__[176] = tmp__[176];
  stateR__[177] = tmp__[177];
  stateR__[178] = tmp__[178];
  stateR__[179] = tmp__[179];
  stateR__[180] = tmp__[180];
  stateR__[181] = tmp__[181];
  stateR__[182] = tmp__[182];
  stateR__[183] = tmp__[183];
  stateR__[184] = tmp__[184];
  stateR__[185] = tmp__[185];
  stateR__[186] = tmp__[186];
  stateR__[187] = tmp__[187];
  stateR__[188] = tmp__[188];
  stateR__[189] = tmp__[189];
  stateR__[190] = tmp__[190];
  stateR__[191] = tmp__[191];
  stateR__[192] = tmp__[192];
  stateR__[193] = tmp__[193];
  stateR__[194] = tmp__[194];
  stateR__[195] = tmp__[195];
  stateR__[196] = tmp__[196];
  stateR__[197] = tmp__[197];
  stateR__[198] = tmp__[198];
  stateR__[199] = tmp__[199];
  stateR__[200] = tmp__[200];
  stateR__[201] = tmp__[201];
  stateR__[202] = tmp__[202];
  stateR__[203] = tmp__[203];
  stateR__[204] = tmp__[204];
  stateR__[205] = tmp__[205];
  stateR__[206] = tmp__[206];
  stateR__[207] = tmp__[207];
  stateR__[208] = tmp__[208];
  stateR__[209] = tmp__[209];
  stateR__[210] = tmp__[210];
  stateR__[211] = tmp__[211];
  stateR__[212] = tmp__[212];
  stateR__[213] = tmp__[213];
  stateR__[214] = tmp__[214];
  stateR__[215] = tmp__[215];
  stateR__[216] = tmp__[216];
  stateR__[217] = tmp__[217];
  stateR__[218] = tmp__[218];
  stateR__[219] = tmp__[219];
  stateR__[220] = tmp__[220];
  stateR__[221] = tmp__[221];
  stateR__[222] = tmp__[222];
  stateR__[223] = tmp__[223];
  stateR__[224] = tmp__[224];
  stateR__[225] = tmp__[225];
  stateR__[226] = tmp__[226];
  stateR__[227] = tmp__[227];
  stateR__[228] = tmp__[228];
  stateR__[229] = tmp__[229];
  stateR__[230] = tmp__[230];
  stateR__[231] = tmp__[231];
  stateR__[232] = tmp__[232];
  stateR__[233] = tmp__[233];
  stateR__[234] = tmp__[234];
  stateR__[235] = tmp__[235];
  stateR__[236] = tmp__[236];
  stateR__[237] = tmp__[237];
  stateR__[238] = tmp__[238];
  stateR__[239] = tmp__[239];
  stateR__[240] = tmp__[240];
  stateR__[241] = tmp__[241];
  stateR__[242] = tmp__[242];
  stateR__[243] = tmp__[243];
  stateR__[244] = tmp__[244];
  stateR__[245] = tmp__[245];
  stateR__[246] = tmp__[246];
  stateR__[247] = tmp__[247];
  stateR__[248] = tmp__[248];
  stateR__[249] = tmp__[249];
  stateR__[250] = tmp__[250];
  stateR__[251] = tmp__[251];
  stateR__[252] = tmp__[252];
  stateR__[253] = tmp__[253];
  stateR__[254] = tmp__[254];
  stateR__[255] = tmp__[255];
  stateR__[256] = tmp__[256];

}

/* Additional functions */
uint32_t bench_speed() {
  /* inputs */
  DATATYPE state__[257] = { 0 };
  /* outputs */
  DATATYPE stateR__[257] = { 0 };
  /* fun call */
  blank__(state__,stateR__);

  /* Returning the number of encrypted bytes */
  return 1028;
}

/* **************************************************************** */
/*                            Usuba source                          */
/*                                                                  */
/*

 node chi(state :  b257 :: base)
  returns stateR :  b257 :: base
vars

let
  forall i in [0,254] {
    (stateR[i]) = (state[i] ^ ((1 ^ state[(i + 1)]) & state[(i + 2)]))
  };
  (stateR[255]) = (state[255] ^ ((1 ^ state[256]) & state[0]));
  (stateR[256]) = (state[256] ^ ((1 ^ state[0]) & state[1]))
tel

 node iota(state :  b257 :: base)
  returns stateR :  b257 :: base
vars

let
  (stateR[0]) = (state[0] ^ 1);
  forall i in [1,256] {
    (stateR[i]) = state[i]
  }
tel

 node theta(state :  b257 :: base)
  returns stateR :  b257 :: base
vars

let
  forall i in [0,256] {
    (stateR[i]) = ((state[i] ^ state[((i + 3) % 257)]) ^ state[((i + 8) % 257)])
  }
tel

 perm phi(state :  b257 :: base)
  returns stateR :  b257 :: base
{
  1, 13, 25, 37, 49, 61, 73, 85, 97, 109, 121, 133, 145, 157, 169, 181, 193, 205, 217, 229, 241, 253, 8, 20, 32, 44, 56, 68, 80, 92, 104, 116, 128, 140, 152, 164, 176, 188, 200, 212, 224, 236, 248, 3, 15, 27, 39, 51, 63, 75, 87, 99, 111, 123, 135, 147, 159, 171, 183, 195, 207, 219, 231, 243, 255, 10, 22, 34, 46, 58, 70, 82, 94, 106, 118, 130, 142, 154, 166, 178, 190, 202, 214, 226, 238, 250, 5, 17, 29, 41, 53, 65, 77, 89, 101, 113, 125, 137, 149, 161, 173, 185, 197, 209, 221, 233, 245, 257, 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132, 144, 156, 168, 180, 192, 204, 216, 228, 240, 252, 7, 19, 31, 43, 55, 67, 79, 91, 103, 115, 127, 139, 151, 163, 175, 187, 199, 211, 223, 235, 247, 2, 14, 26, 38, 50, 62, 74, 86, 98, 110, 122, 134, 146, 158, 170, 182, 194, 206, 218, 230, 242, 254, 9, 21, 33, 45, 57, 69, 81, 93, 105, 117, 129, 141, 153, 165, 177, 189, 201, 213, 225, 237, 249, 4, 16, 28, 40, 52, 64, 76, 88, 100, 112, 124, 136, 148, 160, 172, 184, 196, 208, 220, 232, 244, 256, 11, 23, 35, 47, 59, 71, 83, 95, 107, 119, 131, 143, 155, 167, 179, 191, 203, 215, 227, 239, 251, 6, 18, 30, 42, 54, 66, 78, 90, 102, 114, 126, 138, 150, 162, 174, 186, 198, 210, 222, 234, 246
}


 node round(state :  b257 :: base)
  returns stateR :  b257 :: base
vars

let
  (stateR) = phi(theta(iota(chi(state))))
tel

 node xor1(state :  b257 :: base)
  returns stateR :  b257 :: base
vars

let
  (stateR[0]) = state[0];
  (stateR[1]) = (state[1] ^ 1);
  forall i in [2,256] {
    (stateR[i]) = state[i]
  }
tel

 node blank(state :  b257 :: base)
  returns stateR :  b257 :: base
vars
  tmp :  b257[9] :: base
let
  (tmp[0]) = state;
  forall i in [0,7] {
    (tmp[(i + 1)]) = xor1(round(tmp[i]))
  };
  (stateR) = tmp[8]
tel

*/
 