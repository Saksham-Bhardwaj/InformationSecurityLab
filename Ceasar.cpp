#include <iostream>
#include <cstring>
using namespace std;

string Encrypt(string text , int shift)
{
	string cipher_text="";

	for(int i=0;i<text.length();i++)
	{
		if(isupper(text[i]))
		{
			
			cipher_text += char(int(text[i] -65 + shift)%26+65);
		}
		else
		{
			cipher_text += char(int(text[i] -97 + shift)%26+97);
		}
		
	}

	return cipher_text;
}

string Decrypt(string cipher , int shift)
{
	string text="";

	for(int i=0;i<cipher.length();i++)
	{
		if(isupper(cipher[i]))
		{
			text += char(int(cipher[i] -65 - shift)%26+65);
			
		}
		else
		{
			text += char(int(cipher[i] -97 - shift)%26+97);
			
		}
		
	}

	return text;

}

int main(int argc, char const *argv[])
{

	int shift;
	string text;
	
	cout<<"\nEnter Shift :\t";
	cin>>shift;
	cout<<"\nEnter text :\t";
	cin>>text;

	string encrypt , decrypt;
	encrypt = Encrypt(text,shift);
	decrypt = Decrypt(encrypt,shift);
	
	cout<<"Plain text : "<<text<<endl;
	cout<<"Encrypted : "<<encrypt<<endl;
	cout<<"Decrypted : "<<decrypt<<endl;
	
	return 0;
}
