#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


string getLcs(string seq1,string seq2){
int matrizVec[seq1.size()+1][seq2.size()+1];
for (int i=0;i<=seq1.size();i++){
for (int j=0;j<=seq2.size();j++){
if (i == 0 || j == 0)
matrizVec[i][j]=0;
else if (seq1[i-1] == seq2[j-1])
matrizVec[i][j] = matrizVec[i-1][j-1] + 1;
else
matrizVec[i][j] = max(matrizVec[i-1][j],matrizVec[i][j-1]);
}
}
string lcs;
int i = seq1.size(), j=seq2.size();
while (i!=0 && j!=0){
if (seq1[i-1] == seq2[j-1]){
lcs+=seq1[i-1];
i--;
j--;
}
else if (matrizVec[i-1][j] > matrizVec[i][j-1])
i--;
else
j--;
}
reverse(lcs.begin(),lcs.end());
return lcs;
}

void getCombSeqs(string seq1, string seq2, string lcs){
string combSeqs;
int j=0,k=0;
for (int i=0;i<lcs.size();){
for (j;j<seq1.size();j++){
if (seq1[j]==lcs[i]){
j++;
break;
}
combSeqs+= seq1[j];
}
for (k;k<seq2.size();k++){
if (seq2[k]==lcs[i]){
combSeqs+=lcs[i];
i++;
k++;
break;
}
combSeqs+= seq2[k];
}
}
for (j;j<seq1.size();j++)
combSeqs+= seq1[j];
for (k;k<seq2.size();k++)
combSeqs+= seq2[k];
cout << combSeqs << "\n";
}

int main(){
   ios_base::sync_with_stdio(false);
   string seq1, seq2;
   cin >> seq1;
   bool primeiraLinha = true;
   int instancia = 1;
   while (seq1.compare(0,1,"#") != 0){
      if (!primeiraLinha)
         cout << "\n";
      primeiraLinha=false;
      cin >> seq2;
      cout << "Teste " << instancia << "\n";
      instancia++;
      string lcs=getLcs(seq2, seq1);
        getCombSeqs(seq1,seq2,lcs);
	cin >> seq1;
   }
}
