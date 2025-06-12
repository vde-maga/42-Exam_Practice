unsigned char	reverse_bits(unsigned char octet)
{
	unsigned int	i;
	unsigned char	res = 0;

	i = 8;
	while (i--)
	{
		res = (res << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}


/*


- comecaos pelo fim, logo temos que ter 8 bits
- resultado = qualquer merda e tipo o atoi a converter char para int
- result << 1 esta a gerar espaco em result
- | esta a enviar o result para ser inserido no @resultado de octet
- ou seja, comecamos com 0, ele vai para 00 e enviar o 00 para octet & 1
- octect & 1 esta a verificar a verdade do bit. (0 E 1, logo verdade, logo 1)
- nisto, estou a tornar 00 em 01
- avanco o octect em 1, para trabalhar com o proximo bit


Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100  0001
     ||
     \/
 1000  0010

*/