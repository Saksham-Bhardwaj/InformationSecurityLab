#include<iostream>
#include <cstring>
using namespace std;

char normal[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

char key[] = {'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','I','J','K','L','Z','X','C','V','B','N','M'};

string Encrypt(string text)
{
	string result = "";
	for(int i=0;i<text.length();i++)
	{
		for(int j=0;j<26;j++)
		{
			if(normal[j]==text[i])
			{
				result +=key[j];
			}
		}
	}

	return result;
}


string Decrypt(string text)
{
	string result = "";
	for(int i=0;i<text.length();i++)
	{
		for(int j=0;j<26;j++)
		{
			if(key[j]==text[i])
			{
				result += normal[j];
			}
		}
	}

	return result;
}


int main()
{
	string text , encrypt , decrypt;
	cout<<"\nEnter text : ";
	cin>>text;
	encrypt = Encrypt(text);
	decrypt = Decrypt(encrypt);

	cout<<"\nPlain text : "<<text;
	cout<<"\nEncrypted : "<<encrypt;
	cout<<"\nDecrypted : "<<decrypt<<endl;
	return 0;
}