#include<bits/stdc++.h>

using namespace std;

#define period 5

char key_square[5][5] = {{'R','A','N','C','H'},
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

void encrypt()
{
  string str;
  cout<<"Enter the string to be encrypted : ";
  cin>>str;
  //cin.ignore();
  vector<int> row;
  vector<int> col;

  for(int i =0; i<str.length(); i++)
  {
    //if(str[i] == " ")
    //continue;

    row.push_back(key_row(str[i]));
    col.push_back(key_column(str[i]));
  }

  for(int i =0; i<row.size(); i++)
  {
    cout<<row[i]<<" "<<col[i]<<endl;
  }

  int len = row.size();
  len = len/period;

  cout<<"Length/period : "<<len<<endl;

  vector<int> row_col_merge;

  int j =0;
  int curr = 0;
  int increment =0;

  for(int i =0; i<len; i++)
  {
    curr = j;
    while(j - increment<period)
    {
      row_col_merge.push_back(row[j]);
      j++;
    }
    j = curr;
    while(j - increment<period)
    {
      row_col_merge.push_back(col[j]);
      j++;
    }
    increment += period;
  }

  cout<<"Row column merge : "<<endl;
  for(int i =0; i<row_col_merge.size(); i++)
  {
    cout<<row_col_merge[i]<<" ";
  }
  cout<<endl;

  curr = 0;

  if(j<row.size()-1)
  {
    curr =j;
    while(j<row.size())
    {
      row_col_merge.push_back(row[j]);
      j++;
    }
    j = curr;
    while(j<col.size())
    {
      row_col_merge.push_back(col[j]);
      j++;
    }
  }

  cout<<"Row column merge after adding remaining elements: "<<endl;
  for(int i =0; i<row_col_merge.size(); i++)
  {
    cout<<row_col_merge[i]<<" ";
  }
  cout<<endl;

  string result;

  for(int i =0; i<row_col_merge.size(); i+=2)
  {
    result.push_back(key_square[row_col_merge[i]][row_col_merge[i+1]]);
  }

  cout<<"The encrypted string is : "<<result<<endl;
}

int main()
{

  while(1)
  {
    int c;
    cout<<"Encrypt? 0/1 : ";
    cin>>c;
    if(c==1)
    encrypt();
    else break;
  }

  return 0;
}
