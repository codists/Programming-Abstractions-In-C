
// 定义structure type语法：
/*
typedef struct {
    field-declarations; // structure里面的成员称为field
} name; // structure的名字
*/

// 定义structure
typedef struct {
    char *name;
    char *title;
    char *ssnum;
    double salary;
    int withholding;
} employeeRecordT;



void main() {
    // 声明结构体变量
    employeeRecordT empRc;

    // record selection: empRc.name;

    // 初始化
    empRc.name = "Ebenezer Scrooge";
    empRc.title = "Partner";
    empRc.ssnum = "271-82-8183";
    empRc.salary = 250.00;
    empRc.withholding = 1;

    // 指针与record
     employeeRecordT *empPtr;
     empPtr = &empRc;

    // 指针如何访问record里面的field
    // 方式1：
    (*empPtr).name; // 注意.的优先级高于*
    // 方式2：因为方式1每次都要加括号比较麻烦，所以引入了->操作符
    empPtr->name;

}