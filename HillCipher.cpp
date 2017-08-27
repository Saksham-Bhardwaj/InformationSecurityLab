#include <iostream>
#include <cstring>
using namespace std;
int matrix[3][3] = {{17,17,5},{21,18,21},{2,2,19}};
int Invmatrix[3][3] = {{4,9,15},{15,17,6},{24,0,17}};


string Encrypt(string text)
{
	string result = "";
	for(int k=0;k<text.length();k++)
	{
		text[k] = text[k] - 'a';
		//cout<<int(text[k])<<endl;
	}
	int n = 0;

	for(int n=0; n<text.length();n+=3)
	{
		int c[3]= {0,0,0};
		for(int i=0;i<3;i++)
		{
			
			for(int j=0;j<3;j++)
			{
				c[i] += int(matrix[i][j]*text[n+j]);
			}
		}
		for (int k = 0; k < 3; ++k)
		{
			//cout<<c[k]%26<<endl;
			result += char(c[k]%26 + 65);
		}

	}


	return result;
}

string Decrypt(string text)
{
	string result = "";

	for(int k=0;k<text.length();k++)
	{
		text[k] = text[k] - 'A';
		//cout<<int(text[k])<<endl;

	}

	int n = 0;

	for(int n=0; n<text.length();n+=3)
	{
		int c[3]= {0,0,0};
		for(int i=0;i<3;i++)
		{
			
			for(int j=0;j<3;j++)
			{
				c[i] += int(Invmatrix[i][j]*text[n+j]);
			}
		}
		for (int k = 0; k < 3; ++k)
		{
			//cout<<c[k]%26<<endl;
			result += char(c[k]%26 + 97);
		}

	}
	return result;
}



int main()
{
	string text;
	cout<<"****For encrypting 3 Plain Text characters at a time****";

	cout<<"\nEnter text :\t";
	cin>>text;
	

	string encrypt , decrypt;
	
	encrypt = Encrypt(text);
	decrypt = Decrypt(encrypt);1
	

	//cout<<"Plain text :\t"<<text<<endl;
	cout<<"Encrypted :\t"<<encrypt<<endl;
	cout<<"Decrypted :\t"<<decrypt<<endl;
	
	
	return 0;
}
