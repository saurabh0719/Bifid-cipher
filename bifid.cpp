#include<bits/stdc++.h>

using namespace std;

#define period 3

char key_square = {{'R','A','N','C','H'},
                   {'O','B','D','E','F'},
                   {'G','I','K','L','M'},
                   {'P','Q','S','T','U'},
                   {'V','W','X','Y','Z'}};

int key_row(char c)
{
  if(c=='J')
  return 2;

  for(int i =0; i<5; i++)
  for(int j =0; j<5; j++)
  {
    if(key_square[i][j] == c)
    return i;
  }
}

int key_column(char c)
{
  if(c=='J')
  return 1;

  for(int i =0; i<5; i++)
  for(int j =0; j<5; j++)
  {
    if(key_square[i][j] == c)
    return j;
  }
}

char return_key(int i, int j)
{
  return key_square[i][j];
}

void main()
{

  string str;
  cout<<"Enter the string to be encrypted : ";
  getline(cin,str);
  vector<int> row;
  vector<int> col;

  for(int i =0; i<str.length(); i++)
  {
    row.push(key_row(str[i]));
    col.push(key_col(str[i]));
  }

  int len = row.size();
  len = len/period;

  vector<int> row_col_merge;

  int j =0;

  for(int i =0; i<len; i++)
  {
    int curr = j;
    while(j<=period)
    {
      row_col_merge.push(row[j]);
      j++;
    }
    j = curr;
    while(j<=period)
    {
      row_col_merge.push(col[j]);
      j++;
    }
  }

  if(j<row.length()-1)
  {
    int curr =j;
    while(j<row.length())
    {
      row_col_merge.push(row[j]);
      j++;
    }
    j = curr;
    while(j<col.length())
    {
      row_col_merge.push(col[j]);
      j++;
    }
  }



}
