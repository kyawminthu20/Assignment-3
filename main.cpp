#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include <stdlib.h>

using namespace std;
using std::filesystem::exists;

//********************************************************
// getting line data with vector passed by reference
//********************************************************
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

//********************************************************
//Getting data from text file to 2D array and returning pointer
//********************************************************
char** read_file(int& line_count, int& max_char_count)
{
  bool valid_file = false;
  string file_name, temp_line;
  int count_line = 0;
  ifstream dataIn;
  vector<string> line_data;
  
  // Check file exist with do while loop and exit if user use "exit" string
  do
  {
    cout << endl << "Enter a file name (type exit to end) : ";
    cin >> file_name;
    if(file_name == "exit")
      exit(EXIT_FAILURE);
    //Check File and validate file
    
    dataIn.open(file_name);
    if(dataIn.good())
    {
      valid_file = true;
      cout << file_name << " -- File Exist" << endl;
    }
    else
    {
      cout << file_name <<  " -- File does not exist" << endl;
    }
    dataIn.close();

  }while(valid_file != true);
  //=================================
  // Check how many lines and read all data to vector<string>
  dataIn.open(file_name);
  if (dataIn)
  {
    while(getline(dataIn, temp_line))
    {
      line_data.push_back((temp_line));
    }
  }
  dataIn.close();
  line_count = (int)line_data.size();
  cout << "There are " << line_data.size() << " lines." << endl << endl;
  //===================================
  // testing imported data
  int i = 0, j = 0, k = 0;
  for(i = 0; i < line_data.size(); i++)
  {
    //cout << i+1 << " - " << line_data[i] << " -- " << line_data[i].size() << endl;
    //line_size[i] = line_data[i].size();
    if(max_char_count <= line_data[i].size())
      max_char_count = line_data[i].size();
  }

  //====================================
  // Inserting line data to 2D character array
  char data_sorted[line_data.size()][max_char_count];

  for (i = 0; i < line_data.size(); i++)
  {
    //cout << i << " - " << line_data[i].length() << endl;
    k=0;
    for(int j = line_data[i].length() -1; j >= 0; j--)
    {
      //cout << j << " - " ;
      //cout << line_data[i][j];
      data_sorted[i][k] = line_data[i][j];
      //adding null pointer at the end of the line
      if(j == 0)
        data_sorted[i][k+1] = '\0';
      k++;
    }
    //cout << endl;
  }


  // Checking Data inserted.
  for (i = 0; i < line_data.size(); i++)
  {
    for(k = 0; k < line_data[i].size(); k++)
    {
      cout << data_sorted[i][k];
    }
    cout << endl;
  }
  char *ptr;
  //ptr = new char[sizeof(data_sorted)];
  //cout << sizeof(data_sorted) << endl; 
  //char * ptr = (char *) malloc(sizeof(data_sorted));
  //cout << &data_sorted[0][0] << endl;
  ptr = *data_sorted;
  //cout << ptr << " ==-->>> " << &ptr << endl;
  //cout << endl << endl << ptr << " -- " << endl << *(*(&ptr+7)+1) << endl;
  cout << endl << " -- " << "Testing Pointer" << " -- " << endl;

  int iRow =0, iCol =0;
  
  
  for (iRow = 0; iRow < line_count; iRow++) //Loop of row
  {
    //cout << &main_ptr[iRow];
    //cout << &(ptr+iRow)[iRow];
    //cout << iRow  << endl;
    //cout << ptr + iRow;
      for (iCol = 0; iCol < line_data[iRow].size(); iCol++)// Loop for coloum
      {
          //Read element of 2D array
          cout << (*(ptr + ( iRow * max_char_count) + iCol )) ;
          //cout << *(ptr + ( iRow * max_char_count) + iCol)  ;
          //cout << *(ptr+(iRow*line_data[iRow].size())+iCol);
          //cout << ptr + iRow;

          //cout << &ptr[iRow];
          //cout << &(ptr)[iCol];
          //cout << iCol << " - " ;

      }
      cout << endl;
  }

  cout << "==========" << &ptr << "===============" << &data_sorted << endl << endl;


  return  &ptr;

}

//********************************************************
// Changing vector to string
//********************************************************

string vector_to_string(vector<char> temp)
{
  string s;
  for(char c: temp){
        s.push_back(c);
      }
  return s;

};

//********************************************************
// Printing vector contents
//********************************************************
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
  //char *main_ptr = (char *) malloc(2000);
  int line_count = 0;
  int max_char_count = 0;
  //int line_size[line_count];

  //main_ptr = (char *) malloc(20000);
  char** main_ptr= NULL;
  //main_ptr = new char;
  //main_ptr = (char **) malloc(20000);
  main_ptr = (read_file(line_count, max_char_count));
  //cout << line_count << " " << max_char_count << endl << endl;


  cout << endl << " - " <<  *main_ptr << endl <<  " - " << &main_ptr << endl;

  cout << *(*main_ptr) << endl;

  /*
  int iRow =0, iCol =0;
  for (iRow = 0; iRow < line_count; iRow++) //Loop of row
  {
      //cout << (main_ptr[iRow]) << "--- " << main_ptr;
      
      
      for (iCol = 0; iCol < max_char_count; iCol++)// Loop for coloum
      {
        //Read element of 2D array
        cout << *(main_ptr + ( iRow * max_char_count) + iCol ) ;

        //cout << main_ptr[iRow][iCol];
      }
      
      cout << endl << endl;
  }


  

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

  */
 
  return 0;
}