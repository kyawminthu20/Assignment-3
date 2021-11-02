#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


void read_line(int &line_count, string filename, vector<string> &line_data)
{
  ifstream dataIn;	// defines an input stream for a data file
  int i = 0, j = 0;
  string test;
  dataIn.open(filename);
  if (dataIn)
  {
    while(getline(dataIn, test))
    {
      line_data.push_back((test));
      //cout << data[i] << endl;
      i++;
    }
  }
  line_count = i;
  dataIn.close();
  return;
}

string vector_to_string(vector<char> temp)
{
  string s;
  for(char c: temp){
        s.push_back(c);
      }
  return s;

};

void print_quotes(vector<string> line_data, vector<vector<char>> data, int line_count)
{
  for(int i = 0; i < line_count ; i++)
  {
    for(int j=0; j <= line_data[i].length(); j++)
    {
      cout << data[i][j];
    }
    cout << endl;
  }
}

void search_quotes(vector<string> line_data, vector<vector<char>> data, int line_count, string s)
{
  cout << endl << endl;
  for(int i = 0; i < line_count ; i++)
  {
    vector<char> temp;
    temp.clear();
    for(int j=0; j <= line_data[i].length(); j++)
    {
      //cout << data[i][j];
      temp.push_back(data[i][j]);
    }
    string s_temp = vector_to_string(temp);
    size_t found=s_temp.find(s);
    if (found!=std::string::npos)
      cout << s << " is in " << s_temp;

 
    cout << endl;
  }
}

int main() 

{

  string file_name = "quotes.txt";
  int line_count = 0;
  vector<vector<char>> data;

  // vector array to accept the data from reading the file
  vector<string> line_data; 
  //Read the data and store it in the vector array with reference
  read_line(line_count, file_name,line_data); 
  
  //cout << line_count << endl;

  for(int i = 0; i < line_count ; i++)
  {
    vector<char> temp;

    //cout << line_data[i].length() << endl;
    //cout << line_data[i] << endl;
    for(int j = line_data[i].length(); j >= 0; j--)
    {
      temp.push_back(line_data[i][j]);
      //cout << line_data[i][j];
    }
    data.push_back(temp);
    //cout << endl << endl;
  }

  print_quotes(line_data,data,line_count);

  string s;
  cout << "Enter Search Word : ";
  getline(cin,s);
  search_quotes(line_data,data,line_count,s);
 
  return 0;
}