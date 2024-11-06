# 🏡 Multiple Linear Regression: House Price Prediction 📈

## 📝 Overview
This repository contains a C++ implementation of multiple linear regression for predicting house prices based on feature data. The implementation was created as a solution to a programming challenge that focuses on estimating house prices per square foot using normalised feature values.

## 🔍 Problem Description
Charlie, a prospective homebuyer, has collected detailed data about houses in his target area. He has:
- 🏠 Quantified and normalised various house features on a scale
- 💵 Collected actual price per square foot for some houses
- 📊 Needs to predict prices for houses where pricing is unknown
- 📐 Data shows an approximately linear relationship between features and price

## 💻 Implementation Details
The solution implements multiple linear regression from scratch in C++ using:
- 📐 Custom `LinearRegression` class
- 🔧 Feature centring for numerical stability
- 📘 Normal equation method for coefficient calculation
- ✖️ Direct solution for 2x2 system of equations
- 🔍 Proper handling of intercept terms

### 🧩 Key Components
```cpp
class LinearRegression {
    private:
        vector<double> theta;  // Model coefficients
        
    public:
        void fit(const vector<vector<double>>& X, const vector<double>& y);
        double predict(const vector<double>& x) const;
};
```

## 📂 Usage
### 📥 Input Format
```
F N          // F: number of features, N: number of training examples
x11 x12 y1   // Training data: F features followed by price
x21 x22 y2
...
Q            // Q: number of query houses
q11 q12      // Query data: F features for each house
q21 q22
...
```

### 💡 Example
```
Input:
2 7
0.18 0.89 109.85
1.0 0.26 155.72
0.92 0.11 137.66
0.07 0.37 76.17
0.85 0.16 139.75
0.99 0.41 162.6
0.87 0.47 151.77
4
0.49 0.18
0.57 0.83
0.56 0.64
0.76 0.18

Output:
105.22
142.68
132.94
129.71
```

### ⚙️ Compilation and Running
```bash
g++ -std=c++11 house_price_prediction.cpp -o predict
./predict < input.txt
```

## 🛠️ Technical Details
The implementation uses:
- 🛠️ Standard Template Library (STL)
- 🧮 Vector operations for matrix calculations
- 🧩 Data centring for improved numerical stability
- 📐 Fixed-point output formatting for price predictions

### 📋 Requirements
- C++11 or higher
- Standard C++ libraries

## 🧪 Algorithm
1. 🧮 Centre the training data by subtracting means
2. 🔄 Calculate covariance matrices
3. 📏 Solve normal equations for coefficients
4. ➕ Include intercept term in predictions
5. 💵 Output predictions with 2 decimal places

## 🙏 Acknowledgements
This implementation was created as a solution to a programming challenge focused on multiple linear regression and house price prediction.
