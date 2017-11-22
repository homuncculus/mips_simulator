#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gate.h"
#include "signal.h"
#include "gatedriver.h"

void gatedriver_equation(void)
{
	bus2 A2, B2, C2, D2, F2;
	bus2 U2, V2, W2, Y2, Z2;
	bus2 M2, N2, O2, P2, Q2; 

	A2[2] = B2[2] = C2[2] = D2[2] = F2[2] = '\0';
	U2[2] = V2[2] = W2[2] = Y2[2] = Z2[2] = '\0';
	M2[2] = N2[2] = O2[2] = P2[2] = Q2[2] = '\0';

	A2[0] = A2[1] = B2[0] = C2[1] = '0';
	U2[0] = V2[1] = Y2[0] = Y2[1] = '0';
	B2[1] = U2[1] = '1';	
	C2[0] = V2[0] = '1';	
	D2[0] = D2[1] = W2[0] = W2[1] = '1';	

	/* F = (A OR B) AND (C NOR D) NAND (D NOR B) */
	OR2_2(M2, A2, B2);
	NOR2_2(N2, C2, D2);
	NOR2_2(O2, D2, B2);
	AND2_2(F2, M2, N2);
	NAND2_2(P2, F2, O2);
	printf("F = (A OR B) AND (C NOR D) NAND (D NOR B)\n");
	printf("F = (%s OR %s) AND (%s NOR %s) NAND (%s NOR %s)\n", A2, B2, C2, D2, D2, B2);
	printf("F = %s AND %s NAND %s\n", M2, N2, O2);
	printf("F = %s NAND %s\n", F2, O2);
	printf("F = %s\n\n", P2);

	/* Z = NOT(Y AND W) OR ( U AND V) OR (Y AND U) */
	AND2_2(M2, Y2, W2);
	AND2_2(N2, U2, V2);
	AND2_2(O2, Y2, U2);
	NOT_2(P2, M2);
	OR2_2(Q2, N2, O2);
	OR2_2(Z2, P2, Q2);
	printf("Z = NOT(Y AND W) OR (U AND V) OR (Y AND U)\n");
	printf("Z = NOT(%s AND %s) OR (%s AND %s) OR (%s AND %s)\n", Y2, W2, U2, V2, Y2, U2);
	printf("Z = NOT(%s) OR %s OR %s\n", M2, N2, O2);
	printf("Z = %s OR %s\n", P2, Q2);
	printf("Z = %s\n", Z2);
}

void gatedriver_1(void)
{
	printf("0 * 0 = %c\n", AND2_1('0','0')); 
	printf("0 * 1 = %c\n", AND2_1('0','1')); 
	printf("1 * 0 = %c\n", AND2_1('1','0')); 
	printf("1 * 1 = %c\n", AND2_1('1','1')); 

	printf("0 * 0 * 0 = %c\n", AND3_1('0','0','0')); 
	printf("0 * 0 * 1 = %c\n", AND3_1('0','0','1')); 
	printf("0 * 1 * 0 = %c\n", AND3_1('0','1','0')); 
	printf("0 * 1 * 1 = %c\n", AND3_1('0','1','1')); 

	printf("0 * 0 * 0 * 0 = %c\n", AND4_1('0','0','0','0')); 
	printf("0 * 0 * 0 * 1 = %c\n", AND4_1('0','0','0','1')); 
	printf("0 * 0 * 1 * 0 = %c\n", AND4_1('0','0','1','0')); 
	printf("0 * 0 * 1 * 1 = %c\n", AND4_1('0','0','1','1')); 

	printf("0 * 0 * 0 * 0 * 0 * 0 = %c\n", AND6_1('0','0','0','0','0','0')); 
	printf("0 * 0 * 0 * 0 * 0 * 1 = %c\n", AND6_1('0','0','0','0','0','1')); 
	printf("0 * 0 * 0 * 0 * 1 * 0 = %c\n", AND6_1('0','0','0','0','1','0')); 
	printf("0 * 0 * 0 * 0 * 1 * 1 = %c\n", AND6_1('0','0','0','0','1','1')); 

	printf("0 * 0 * 0 * 0 * 0 * 0 * 0 = %c\n", AND8_1('0','0','0','0','0','0','0','0')); 
	printf("0 * 0 * 0 * 0 * 0 * 0 * 1 = %c\n", AND8_1('0','0','0','0','0','0','0','1')); 
	printf("0 * 0 * 0 * 0 * 0 * 1 * 0 = %c\n", AND8_1('0','0','0','0','0','0','1','0')); 
	printf("0 * 0 * 0 * 0 * 0 * 1 * 1 = %c\n", AND8_1('0','0','0','0','0','0','1','1')); 

	printf("(0 * 0)' = %c\n", NAND2_1('0','0')); 
	printf("(0 * 1)' = %c\n", NAND2_1('0','1')); 
	printf("(1 * 0)' = %c\n", NAND2_1('1','0')); 
	printf("(1 * 1)' = %c\n", NAND2_1('1','1')); 

	printf("(0 * 0 * 0)' = %c\n", NAND3_1('0','0','0')); 
	printf("(0 * 0 * 1)' = %c\n", NAND3_1('0','0','1')); 
	printf("(0 * 1 * 0)' = %c\n", NAND3_1('0','1','0')); 
	printf("(0 * 1 * 1)' = %c\n", NAND3_1('0','1','1')); 

	printf("(0 * 0 * 0 * 0)' = %c\n", NAND4_1('0','0','0','0')); 
	printf("(0 * 0 * 0 * 1)' = %c\n", NAND4_1('0','0','0','1')); 
	printf("(0 * 0 * 1 * 0)' = %c\n", NAND4_1('0','0','1','0')); 
	printf("(0 * 0 * 1 * 1)' = %c\n", NAND4_1('0','0','1','1')); 

	printf("(0 * 0 * 0 * 0 * 0 * 0)' = %c\n", NAND6_1('0','0','0','0','0','0')); 
	printf("(0 * 0 * 0 * 0 * 0 * 1)' = %c\n", NAND6_1('0','0','0','0','0','1')); 
	printf("(0 * 0 * 0 * 0 * 1 * 0)' = %c\n", NAND6_1('0','0','0','0','1','0')); 
	printf("(0 * 0 * 0 * 0 * 1 * 1)' = %c\n", NAND6_1('0','0','0','0','1','1')); 

	printf("(0 * 0 * 0 * 0 * 0 * 0 * 0)' = %c\n", NAND8_1('0','0','0','0','0','0','0','0')); 
	printf("(0 * 0 * 0 * 0 * 0 * 0 * 1)' = %c\n", NAND8_1('0','0','0','0','0','0','0','1')); 
	printf("(0 * 0 * 0 * 0 * 0 * 1 * 0)' = %c\n", NAND8_1('0','0','0','0','0','0','1','0')); 

	printf("(0 + 0)' = %c\n", NOR2_1('0','0')); 
	printf("(0 + 1)' = %c\n", NOR2_1('0','1')); 
	printf("(1 + 0)' = %c\n", NOR2_1('1','0')); 
	printf("(1 + 1)' = %c\n", NOR2_1('1','1')); 

	printf("(0 + 0 + 0)' = %c\n", NOR3_1('0','0','0')); 
	printf("(0 + 0 + 1)' = %c\n", NOR3_1('0','0','1')); 
	printf("(0 + 1 + 0)' = %c\n", NOR3_1('0','1','0')); 
	printf("(0 + 1 + 1)' = %c\n", NOR3_1('0','1','1')); 

	printf("(0 + 0 + 0 + 0)' = %c\n", NOR4_1('0','0','0','0')); 
	printf("(0 + 0 + 0 + 1)' = %c\n", NOR4_1('0','0','0','1')); 
	printf("(0 + 0 + 1 + 0)' = %c\n", NOR4_1('0','0','1','0')); 
	printf("(0 + 0 + 1 + 1)' = %c\n", NOR4_1('0','0','1','1')); 

	printf("(0 + 0 + 0 + 0 + 0 + 0)' = %c\n", NOR6_1('0','0','0','0','0','0')); 
	printf("(0 + 0 + 0 + 0 + 0 + 1)' = %c\n", NOR6_1('0','0','0','0','0','1')); 
	printf("(0 + 0 + 0 + 0 + 1 + 0)' = %c\n", NOR6_1('0','0','0','0','1','0')); 
	printf("(0 + 0 + 0 + 0 + 1 + 1)' = %c\n", NOR6_1('0','0','0','0','1','1')); 

	printf("(0 + 0 + 0 + 0 + 0 + 0 + 0)' = %c\n", NOR8_1('0','0','0','0','0','0','0','0')); 
	printf("(0 + 0 + 0 + 0 + 0 + 0 + 1)' = %c\n", NOR8_1('0','0','0','0','0','0','0','1')); 
	printf("(0 + 0 + 0 + 0 + 0 + 1 + 0)' = %c\n", NOR8_1('0','0','0','0','0','0','1','0')); 

	printf("0' = %c\n", NOT_1('0')); 
	printf("1' = %c\n", NOT_1('1')); 

	printf("0 + 0 = %c\n", OR2_1('0','0')); 
	printf("0 + 1 = %c\n", OR2_1('0','1')); 
	printf("1 + 0 = %c\n", OR2_1('1','0')); 
	printf("1 + 1 = %c\n", OR2_1('1','1')); 

	printf("0 + 0 + 0 = %c\n", OR3_1('0','0','0')); 
	printf("0 + 0 + 1 = %c\n", OR3_1('0','0','1')); 
	printf("0 + 1 + 0 = %c\n", OR3_1('0','1','0')); 
	printf("0 + 1 + 1 = %c\n", OR3_1('0','1','1')); 

	printf("0 + 0 + 0 + 0 = %c\n", OR4_1('0','0','0','0')); 
	printf("0 + 0 + 0 + 1 = %c\n", OR4_1('0','0','0','1')); 
	printf("0 + 0 + 1 + 0 = %c\n", OR4_1('0','0','1','0')); 
	printf("0 + 0 + 1 + 1 = %c\n", OR4_1('0','0','1','1')); 

	printf("0 + 0 + 0 + 0 + 0 + 0 = %c\n", OR6_1('0','0','0','0','0','0')); 
	printf("0 + 0 + 0 + 0 + 0 + 1 = %c\n", OR6_1('0','0','0','0','0','1')); 
	printf("0 + 0 + 0 + 0 + 1 + 0 = %c\n", OR6_1('0','0','0','0','1','0')); 
	printf("0 + 0 + 0 + 0 + 1 + 1 = %c\n", OR6_1('0','0','0','0','1','1')); 

	printf("0 + 0 + 0 + 0 + 0 + 0 + 0 = %c\n", OR8_1('0','0','0','0','0','0','0','0')); 
	printf("0 + 0 + 0 + 0 + 0 + 0 + 1 = %c\n", OR8_1('0','0','0','0','0','0','0','1')); 
	printf("0 + 0 + 0 + 0 + 0 + 1 + 0 = %c\n", OR8_1('0','0','0','0','0','0','1','0')); 
	printf("0 + 0 + 0 + 0 + 0 + 1 + 1 = %c\n", OR8_1('0','0','0','0','0','0','1','1')); 

	printf("0 XNOR 0 = %c\n", XNOR2_1('0','0')); 
	printf("0 XNOR 1 = %c\n", XNOR2_1('0','1')); 
	printf("1 XNOR 0 = %c\n", XNOR2_1('1','0')); 
	printf("1 XNOR 1 = %c\n", XNOR2_1('1','1')); 

	printf("0 XNOR 0 XNOR 0 = %c\n", XNOR3_1('0','0','0')); 
	printf("0 XNOR 0 XNOR 1 = %c\n", XNOR3_1('0','0','1')); 
	printf("0 XNOR 1 XNOR 0 = %c\n", XNOR3_1('0','1','0')); 
	printf("1 XNOR 1 XNOR 1 = %c\n", XNOR3_1('1','1','1')); 

	printf("0 XNOR 0 XNOR 0 XNOR 0 = %c\n", XNOR4_1('0','0','0','0')); 
	printf("0 XNOR 0 XNOR 0 XNOR 1 = %c\n", XNOR4_1('0','0','0','1')); 
	printf("0 XNOR 0 XNOR 1 XNOR 0 = %c\n", XNOR4_1('0','0','1','0')); 
	printf("1 XNOR 1 XNOR 1 XNOR 1 = %c\n", XNOR4_1('1','1','1','1')); 

	printf("0 XNOR 0 XNOR 0 XNOR 0 XNOR 0 XNOR 0 = %c\n", XNOR6_1('0','0','0','0','0','0')); 
	printf("0 XNOR 0 XNOR 0 XNOR 0 XNOR 0 XNOR 1 = %c\n", XNOR6_1('0','0','0','0','0','1')); 
	printf("0 XNOR 0 XNOR 0 XNOR 0 XNOR 1 XNOR 0 = %c\n", XNOR6_1('0','0','0','0','1','0')); 
	printf("0 XNOR 0 XNOR 0 XNOR 0 XNOR 1 XNOR 1 = %c\n", XNOR6_1('0','0','0','0','1','1')); 

	printf("0 XNOR 0 XNOR 0 XNOR 0 XNOR 0 XNOR 0 XNOR 0 = %c\n", XNOR8_1('0','0','0','0','0','0','0','0')); 
	printf("0 XNOR 0 XNOR 0 XNOR 0 XNOR 0 XNOR 0 XNOR 1 = %c\n", XNOR8_1('0','0','0','0','0','0','0','1')); 
	printf("0 XNOR 0 XNOR 0 XNOR 0 XNOR 0 XNOR 1 XNOR 0 = %c\n", XNOR8_1('0','0','0','0','0','0','1','0')); 
	printf("0 XNOR 0 XNOR 0 XNOR 0 XNOR 0 XNOR 1 XNOR 1 = %c\n", XNOR8_1('0','0','0','0','0','0','1','1')); 

	printf("0 XOR 0 = %c\n", XOR2_1('0','0')); 
	printf("0 XOR 1 = %c\n", XOR2_1('0','1')); 
	printf("1 XOR 0 = %c\n", XOR2_1('1','0')); 
	printf("1 XOR 1 = %c\n", XOR2_1('1','1')); 

	printf("0 XOR 0 XOR 0 = %c\n", XOR3_1('0','0','0')); 
	printf("0 XOR 0 XOR 1 = %c\n", XOR3_1('0','0','1')); 
	printf("0 XOR 1 XOR 0 = %c\n", XOR3_1('0','1','0')); 
	printf("1 XOR 1 XOR 1 = %c\n", XOR3_1('1','1','1')); 

	printf("0 XOR 0 XOR 0 XOR 0 = %c\n", XOR4_1('0','0','0','0')); 
	printf("0 XOR 0 XOR 0 XOR 1 = %c\n", XOR4_1('0','0','0','1')); 
	printf("0 XOR 0 XOR 1 XOR 0 = %c\n", XOR4_1('0','0','1','0')); 
	printf("1 XOR 1 XOR 1 XOR 1 = %c\n", XOR4_1('1','1','1','1')); 

	printf("0 XOR 0 XOR 0 XOR 0 XOR 0 XOR 0 = %c\n", XOR6_1('0','0','0','0','0','0')); 
	printf("0 XOR 0 XOR 0 XOR 0 XOR 0 XOR 1 = %c\n", XOR6_1('0','0','0','0','0','1')); 
	printf("0 XOR 0 XOR 0 XOR 0 XOR 1 XOR 0 = %c\n", XOR6_1('0','0','0','0','1','0')); 
	printf("0 XOR 0 XOR 0 XOR 0 XOR 1 XOR 1 = %c\n", XOR6_1('0','0','0','0','1','1')); 

	printf("0 XOR 0 XOR 0 XOR 0 XOR 0 XOR 0 XOR 0 = %c\n", XOR8_1('0','0','0','0','0','0','0','0')); 
	printf("0 XOR 0 XOR 0 XOR 0 XOR 0 XOR 0 XOR 1 = %c\n", XOR8_1('0','0','0','0','0','0','0','1')); 
	printf("0 XOR 0 XOR 0 XOR 0 XOR 0 XOR 1 XOR 0 = %c\n", XOR8_1('0','0','0','0','0','0','1','0')); 
	printf("0 XOR 0 XOR 0 XOR 0 XOR 0 XOR 1 XOR 1 = %c\n", XOR8_1('0','0','0','0','0','0','1','1')); 

}

void gatedriver_32(void)
{
	char signal1[33] = "00110011001100110011001100110011\0";
	char signal2[33] = "01010101010101010101010101010101\0";
	char output[33];
	output[32] = '\0';

	AND2_32(output, signal1, signal2); 
	printf("\t%s\n*\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, output); 

	AND3_32(output, signal1, signal2, signal1); 
	printf("\t%s\n\t%s\n*\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, output); 

	AND4_32(output, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n*\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, output); 

	AND6_32(output, signal1, signal2, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n*\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, signal1, signal2, output); 

	AND8_32(output, signal1, signal2, signal1, signal2, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n*\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, signal1, signal2, signal1, signal2, output); 

	NAND2_32(output, signal1, signal2); 
	printf("\t%s\n*'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, output); 

	NAND3_32(output, signal1, signal2, signal1); 
	printf("\t%s\n\t%s\n*'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, output); 

	NAND4_32(output, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n*'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, output); 

	NAND6_32(output, signal1, signal2, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n*'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, signal1, signal2, output); 

	NAND8_32(output, signal1, signal2, signal1, signal2, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n*'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, signal1, signal2, signal1, signal2, output); 

	NOR2_32(output, signal1, signal2); 
	printf("\t%s\n+'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, output); 

	NOR3_32(output, signal1, signal2, signal1); 
	printf("\t%s\n\t%s\n+'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, output); 

	NOR4_32(output, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n+'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, output); 

	NOR6_32(output, signal1, signal2, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n+'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, signal1, signal2, output); 

	NOR8_32(output, signal1, signal2, signal1, signal2, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n+'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, signal1, signal2, signal1, signal2, output); 

	OR2_32(output, signal1, signal2); 
	printf("\t%s\n+\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, output); 

	OR3_32(output, signal1, signal2, signal1); 
	printf("\t%s\n\t%s\n+\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, output); 

	OR4_32(output, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n+\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, output); 

	OR6_32(output, signal1, signal2, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n+\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, signal1, signal2, output); 

	OR8_32(output, signal1, signal2, signal1, signal2, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n+\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, signal1, signal2, signal1, signal2, output); 

	XOR2_32(output, signal1, signal2); 
	printf("\t%s\nXOR\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, output); 

	XOR3_32(output, signal1, signal2, signal1); 
	printf("\t%s\n\t%s\nXOR\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, output); 

	XOR4_32(output, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\nXOR\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, output); 

	XOR6_32(output, signal1, signal2, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n\t%s\n\t%s\nXOR\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, signal1, signal2, output); 

	XOR8_32(output, signal1, signal2, signal1, signal2, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\nXOR\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, signal1, signal2, signal1, signal2, output); 

	XNOR2_32(output, signal1, signal2); 
	printf("\t%s\nXOR'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, output); 

	XNOR3_32(output, signal1, signal2, signal1); 
	printf("\t%s\n\t%s\nXOR'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, output); 

	XNOR4_32(output, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\nXOR'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, output); 

	XNOR6_32(output, signal1, signal2, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n\t%s\n\t%s\nXOR'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, signal1, signal2, output); 

	XNOR8_32(output, signal1, signal2, signal1, signal2, signal1, signal2, signal1, signal2); 
	printf("\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\nXOR'\t%s\n----------------------------------------\n\t%s\n\n", signal1, signal2, signal1, signal2, signal1, signal2, signal1, signal2, output); 

}
