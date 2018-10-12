'''
程式語言：python
請用任何方式，儲存小明、小美、老王三人的國英數考試成績。

並設計一函式，可以查詢某一位同學的成績
'''

def getGradeByName(studentList, name):
    for student in studentList:
        if student["name"] == name:
            print("Chinese:" + str(student["chi"]))
            print("English:" + str(student.get("eng")))
            print("Math:" + str(student["math"]), end="")
            print("\n\n\n")

def getGradeByNum(studentList, num):
    # for i in range(0, len(studentList)):
    for i in range(len(studentList)):
        if studentList[i]["num"] == num:
            # student = studentList[i]
            print("Chinese:" + str(studentList[i]["chi"]))
            print("English:" + str(studentList[i].get("eng")))
            print("Math:" + str(studentList[i]["math"]), end="")
            print("\n\n\n")

if __name__ == "__main__":
    
    studentList = [
        {
            "num":1,
            "name":"小明",
            "chi":90,
            "eng":90,
            "math":98
        },
        {
            "num":2,
            "name":"小美",
            "chi":98,
            "eng":87,
            "math":95
        }
    ]
    #wang = {
    #    "num":3,
    #    "name":"老王",
    #    "chi":78,
    #    "eng":86,
    #    "math":88
    #}
    studentList.append({
        "num":3,
        "name":"老王",
        "chi":78,
        "eng":86,
        "math":88
    })
    #studentList.append(wang)
    getGradeByName(studentList, "小美")
    getGradeByName(studentList, "老王")
    getGradeByNum(studentList, 1)