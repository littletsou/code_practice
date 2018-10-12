def add(num1, num2):
    return num1 + num2

def sub(num1, num2):
    return num1 - num2

def mult(num1, num2):
    return num1 * num2

def div(num1, num2):
    return num1 / num2

class calc:

    def __init__(self, num1, num2):
        self.num1 = num1
        self.num2 = num2
        self.result = 0
    def add(self):
        self.result = self.num1 + self.num2
        return self.result

    def sub(self):
        self.result = self.num1 - self.num2
        return self.result

    def mult(self):
        self.result = self.num1 * self.num2
        return self.result

    def div(self):
        try:
            self.result = self.num1 / self.num2
        except:
            print("Unknown error")
        return self.result
    def getResult(self):
        return str(self.result)

if __name__ == "__main__":
    calc1 = calc(1, 2)
    calc2 = calc(3, 4)
    calc3 = calc(5, 6)
    calc4 = calc(1, 0)
    calc1.add()
    print("calc1 add: " + str(calc1.add()))
    calc1.getResult()

    calc2.sub()
    print("calc2 sub: " + str(calc2.sub()))

    print("calc3 mult: " + str(calc3.mult()))

    calc4.div()
    print("calc4 div: " + calc4.getResult())

    print("hello world")
    num1 = int(input("Enter num1: "))
    num2 = int(input("Enter num2: "))
    add_result = num1 + num2
    add_result = add(num1, num2)
    sub_result = sub(num1, num2)
    mult_result = mult(num1, num2)
    div_result = div(num1, num2)
    print("add_result: " + str(add_result))
    print("sub_result: " + str(sub_result))
    print("mult_result: " + str(mult_result))
    print("div_result: " + str(div_result))

