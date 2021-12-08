# 自助咖啡厅

## 主要实现：设计一个自助购买咖啡系统，实现购买咖啡的过程。

### (1) 商品管理：

​		分类、显示商品、添加商品、修改商品数量和价格，如商品有 咖啡、牛奶、糖、冰、杯子

#### (2) 会员信息管理：

​			注册、登录，基本信息维护

#### (3) 订单管理：

​		显示订单、删除订单、查询订单

#### (4) 支付功能 ：

​		模拟支付（支付宝，微信）

#### (5) 自提、配送

​		类设计提示（不局限于以下类）：

#### 商品：

​		商品编号、名称、数量、价格

#### 订单：

​		商品、数量、价格；

#### 会员管理：

​		编号、姓名、电话等


--------------------------------------------------------------------------------------------------------------------
# 基本框架

## 1商品类Commodity

### 	功能：

​		**支付，显示商品，冷热**

### 	成员：

​		**编号，咖啡名字，数量，价格**

# 2后台管理类Back_stage_management

## 	功能

​		**管理员登陆，添加商品，修改商品数量和价格**

## 	成员

​		**管理员账号，密码**

# 3订单类Order

## 	***功能***

​		**显示订单，删除订单，查询订单，选择自提或者配送**

## 	成员

​		**配送时间，订单编号**

# 4界面类Interface

​	**查看订单，购买，会员登陆，后台管理员登陆**

# 5原材料类Raw_material

​		**咖啡，糖，冰，牛奶和杯子的数量**

# 6会员类VIP

## 	功能

​		**注册，登录，找回密码**

## 	成员

​		**账号，密码，姓名，电话，编号**