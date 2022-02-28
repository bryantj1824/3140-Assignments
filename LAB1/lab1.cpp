// This file shows basic functions of reading in a CSV file using C++98
// Please add your name to your code! 

/* Homework Objective: fix this program to match the requirements listed: 
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category 
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.

All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(

*/

#include <cstdlib>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>

using namespace std; 

/**
 * Will Print out a 2 dimension vector
 */
string print_2d_vector( vector< vector<string> > csv_data ){

  stringstream output;

  for( int i =0; i < csv_data.size(); i++ ){ // Loops through csv_data or csv rows

    vector<string> csv_row = csv_data.at(i); // Initates vector csv_row

    for( int x =0; x < csv_row.size(); x++ ){ // Loops through vector csv_row

      output << csv_row.at(x) << " ";

    }

    output << endl;

  }

  return output.str();

}

/**
 * Will return a 2d vector where the first dimension of vectors represents csv rows
 * and the elements in the second dimension vector represents columns
 */
vector< vector<string> > get_csv_data(string file){

  vector< vector<string> > csv_data;

  ifstream in_stream;

  string line;

  in_stream.open(file.c_str()); //opening the file.

  if (in_stream.is_open()){ // File is open

    while( getline(in_stream, line) ){ // Loop through first line / csv row

      vector<string> csv_row; // Initates vector csv_row

      while( line.length() > 0 ){ // While length still has characters

        // Position of next comma in line
        int comma_pos = line.find(',');

        if (comma_pos == -1){ // Comma not found
          csv_row.push_back(line); // Saving the rest of line to csv_row
          break; // Ends while loop
        }

        // Gets string before the next comma
        string column = line.substr(0, comma_pos); 

        // Removes string before comma position from line and removes comma
        line.erase(0, comma_pos + 1); 

        // Adding the column data to vector element csv_row
        csv_row.push_back(column);

      }

      // Adding the vector csv_row to csv_data
      csv_data.push_back(csv_row);

    }

    in_stream.close(); // Closes File
  }

  return csv_data;

}

/**
 * Calculates the average price by brand or category (decided by second parameter)
 * and returns a string stream with string of results 
 * 
 * @param csv_data          - A 2d vector representation of csv data
 * @param brand_or_category - A string "brand" or "category", 
 * will decide whether we calculate average price by brand or category
 */
string calculate_brands_or_category_average_price( vector< vector<string> > csv_data, string brand_or_category){

  stringstream output;

  map< string, vector<string> > brands_or_category_prices;

  // Will keep track of column index of brand_or_category and price
  int position_of_brand_or_category, position_of_price;

  // Step 1: Find the position of brand and price from csv_data header
  vector<string> csv_header = csv_data.at(0);
  for( int i = 0; i < csv_header.size(); i++ ){
    string col_data = csv_header.at(i);

    // Assigns column index of price to position_of_price
    if (col_data == "price"){ position_of_price = i; }

    // Assigns column index of brand or category to position_of_brand_or_category
    if(col_data == brand_or_category){ position_of_brand_or_category = i; }

  }

  // Step 2: Loop through all rows and organize prices by brands
  for( int i = 1; i < csv_data.size(); i++ ){

    vector<string> csv_row = csv_data.at(i); // csv row

    string brand_or_category_name = csv_row.at(position_of_brand_or_category); // Gets current rows brand

    string price = csv_row.at(position_of_price); // Gets current rows price

    // Associates price to brands_or_category_prices vector in brands var
    brands_or_category_prices[brand_or_category_name].push_back(price); 

  }

  // Step 3: Loop through grouped brand data and brands prices and calculate average prices
  map< string, vector<string> >::iterator brands_or_category_prices_iterator = brands_or_category_prices.begin();
  while( brands_or_category_prices_iterator != brands_or_category_prices.end() ){

      string brand_or_category_name = brands_or_category_prices_iterator->first;
      vector<string> prices = brands_or_category_prices_iterator->second;

      int price_count = prices.size();
      double average_price = 0;

      // Looping through prices for brand
      for( int i = 0; i < price_count; i++ ){
        average_price += atof(prices.at(i).c_str());
      }

      average_price = average_price / price_count;

      output << brand_or_category << " " << brand_or_category_name << " has an average price of: " << average_price << endl;

      brands_or_category_prices_iterator++;
  }

  return output.str();

}

string print_sku_list( vector< vector<string> > csv_data ){

  stringstream output;

  map<string, vector<string> > skus_by_year;

   // Will keep track of column index for sku and year
  int position_of_sku, position_of_year;

  // Step 1: Find the position of sku and year from csv_data header
  vector<string> csv_header = csv_data.at(0);
  for( int i = 0; i < csv_header.size(); i++ ){
    string col_data = csv_header.at(i);

    // Assigns column index of price to position_of_price
    if (col_data == "sku"){ position_of_sku = i; }

    // Assigns column index of brand or category to position_of_brand_or_category
    if(col_data == "year"){ position_of_year = i; }

  }

  // Step 2: Loop through all rows and organize skus by year
  for( int i = 1; i < csv_data.size(); i++ ){

    vector<string> csv_row = csv_data.at(i); // csv row

    string year = csv_row.at(position_of_year); // Gets current rows year

    string sku = csv_row.at(position_of_sku); // Gets current rows sku

    // Associates sku to a year, using skus vector variable
    skus_by_year[year].push_back(sku); 

  }

   // Step 3: Loop through grouped skus
  map<string, vector<string> >::iterator skus_iterator = skus_by_year.begin();

  while( skus_iterator != skus_by_year.end() ){

      string year = skus_iterator->first;
      vector<string> skus = skus_iterator->second;

      output << "Year" << year << "(" << skus.size() << "): ";

      // Looping through skus by year
      for( int i = 0; i < skus.size() ; i++ ){

        output << skus.at(i) + " ";

      }

      output << endl;

      skus_iterator++;
  }

  return output.str();

}

int main(){

  string output = "";

  // Stores 2 dimension vector of rows and columns in csv_data
  vector< vector<string> > csv_data = get_csv_data("data.csv");

  // Each function below returns a string of results
  // We save the string results to output to later output results to results.txt file
  output += print_2d_vector(csv_data)  + "\n";

  output += calculate_brands_or_category_average_price(csv_data, "brand") + "\n";

  output += calculate_brands_or_category_average_price(csv_data, "category") + "\n";

  output += print_sku_list(csv_data) + "\n";

  ofstream file("results.txt");

  if (file.is_open()){
    file << output;
  }else{
    cout << "Sorry could not open file" << endl;
  }

  file.close();

  return 0;
}