# Require Packages
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn import datasets,linear_model

# Function to get data
def get_data(file_name):
    data = pd.read_csv(file_name)       # 将.csv数据读入Pandas数据帧
    X_parameter = []
    Y_parameter = []
    for single_square_feet ,single_prince_value in zip(data['area'],data['price']): # .csv中的列名
        X_parameter.append([float(single_square_feet)])
        Y_parameter.append(float(single_prince_value))
    return X_parameter,Y_parameter

#print(get_data('input_data.csv'))

# Function for Fitting our data to Linear model
def linear_model_main(X_parameters,Y_parameters,predict_value):# Create Linear regression object
    regr = linear_model.LinearRegression()  # 创建线性模型
    regr.fit(X_parameters,Y_parameters)     # 用我们的X_parameters和Y_parameter训练它
    predict_outcome = regr.predict(predict_value)
    predictions = {}        #我们创建一个名称为predictions的字典，存着θ0、θ1和预测值，
                            # 并返回predictions字典为输出。
    predictions['intercept'] = regr.intercept_      # 截距值 theta0
    predictions['coefficient'] = regr.coef_        # 系数 theta1
    predictions['predicted_value'] = predict_outcome
    return predictions

X,Y = get_data('input_data.csv')
predictvalue = 700
result = linear_model_main(X,Y,predictvalue)
print ("Theta0 : " ,result['intercept'])
print ("Theta1 : " ,result['coefficient'])
print ("Predicted value : " ,result['predicted_value'])

# Function to show the results of linear fit model
def show_linear_line(X_parameters,Y_parameters):# Create linear regression object
    regr = linear_model.LinearRegression()
    regr.fit(X_parameters,Y_parameters)
    plt.scatter(X_parameters,Y_parameters,color='blue')
    plt.plot(X_parameters,regr.predict(X_parameters),color='red',linewidth=4)
    plt.xticks(())
    plt.yticks(())
    plt.show()
show_linear_line(X,Y)