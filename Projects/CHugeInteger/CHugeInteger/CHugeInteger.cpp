#include "CHugeInteger.h"

CHugeInteger::CHugeInteger(const CHugeInteger & src) {//создаем новый масств размера size
	size = src.size;
	num = new int[size];
	for (int i = 0; i < size; ++i)
		num[i] = src.num[i];                                   
}

CHugeInteger::CHugeInteger(int s) {
	size = s;
	num = new int[size];
	for (int i = 0; i < size; ++i)
		num[i] = 0;
}

void CHugeInteger::read() {
	string number;
	cin >> number;
	size = number.length();
	num = new int[size];
	for (int i = 0; i < size ; i++)
		num[i] = number[size - i - 1] - 48;
}

void CHugeInteger::Print() const {
	for (int i = size - 1; i >= 0 ; --i) {
		cout << num[i];
	}
}

CHugeInteger CHugeInteger::operator = (const CHugeInteger & src) {
	if (this == &src)
		return *this;
	delete [] num;
	num = new int[size = src.size];
	for (int i = 0; i < size; ++i)
		num[i] = src.num[i];
	return *this;
}

CHugeInteger::~CHugeInteger() {
	delete []num;
}

CHugeInteger CHugeInteger::operator + (const CHugeInteger & b) const {
	CHugeInteger c(max(size, b.size) + 1);
	int count = 0;    
	for (int i = 0; i < c.size - 1; ++i) {
		int a = 0, d = 0;
		if (i < size)
			a = num[i];
		if (i < b.size)
			d = b.num[i];
		c.num[i] = (a + d + count) % 10;
		count = (a + d + count) / 10;    
	}
	if (count == 1)
		c.num[c.size - 1] = 1;
	else 
		c.size--;
	return c;
}

CHugeInteger CHugeInteger::operator-(const CHugeInteger & b) const {
	CHugeInteger c(size);
	if (*this == b) {
		c.size = 1;
		return c;
	}
	int count = 0;
	for (int i = 0; i < size; ++i) {
		int temp1 = num[i] - count;
		int temp2 = b.num[i];
		if (i >= b.size)
			temp2 = 0; 
		if (temp1 >= temp2) {
			c.num[i] = temp1 - temp2; 
			count = 0;                          //оператор вычитания
		} else { 
			c.num[i] = 10 + temp1 - temp2;
			count = 1;
		}
	}
	for (int i = size - 1; i > 0; --i) {      
		if (!c.num[i])
			c.size--;
		else 
			break;   
	}
	return c;
}     

CHugeInteger CHugeInteger::mult(const int& b, int shift) const {

	CHugeInteger c(size + shift + 1);//шифт считает сколько нулей нужно отступать
	int count = 0;

	for (int i = shift; i < size+shift; i++) {
		c.num[i] = (num[i-shift] * b + count)%10;
		count = (num[i-shift] * b + count) / 10;
	}

	if (count != 0)
		c.num[c.size - 1] = count;
	else 
		c.size--;

	return c;//функция умножения одного разряда на число начиная с первого разряда(с конца)
}
//---------------------------------------------------
CHugeInteger CHugeInteger::operator *(const CHugeInteger & b) const {
	CHugeInteger c(1);
	if ((size == 1 && num[0] == 0) || (b.size == 1 && b.num[0] == 0))
		return c;
	for (int i = 0; i < size; ++i) 
		c = b.mult(num[i], i) + c ; 
	if (c.num[c.size - 1] == 0)
		--c.size;
	return c;//оператор умножения используем мульт size раз
}          
bool CHugeInteger::operator < (const CHugeInteger & b) const {

	if (!(*this>b) && !(*this==b))
		return 1;
	else 
		return 0;
}                   
//---------------------------------------------------
bool CHugeInteger::operator >(const CHugeInteger & b) const {

	int i;
	if (size > b.size) 
		return 1;
	if (size < b.size) 
		return 0;
	for (i = size - 1; i >= 0 ; --i) {
		if (num[i] == b.num[i]) 
			continue;
		if (num[i] > b.num[i]) 
			return 1;
		else        
			return 0;
	}
	if (i < 0)
		return 0; 
}        
 
bool CHugeInteger::operator ==(const CHugeInteger & b) const {
	int i;
	if (size != b.size) 
		return 0;
	for (i = size - 1; i >= 0 ; --i) {
		if (num[i] == b.num[i]) 
			continue;
		return 0;
	}
	if (i < 0)
		return 1;
}     

CHugeInteger CHugeInteger::operator -=(const CHugeInteger & b) {
	*this = *this - b;
	return *this;           //оператор уменьшения ообъекта на число  b типа CHI без создания нового оъекта 
}   

CHugeInteger CHugeInteger::substring(int b) {//выделяем подстроку размера длины b
	CHugeInteger c(b);
	for (int i = size - 1, j = c.size - 1; j >= 0; --j, --i) 
		c.num[j] = num[i];            
	return c; 
}

CHugeInteger CHugeInteger::addNum(int b) {
	if (size == 1 && num[0] == 0 ) {
		if (b == 0)      
			return *this;
		else { 
			CHugeInteger d(1);
			d.num[0] = b;
			return d;
		} 
	}
	CHugeInteger c(size + 1);
	for (int i = size; i > 0; --i)  
		c.num[i] = num[i - 1];       
	c.num[0] = b;
	return c;//сдвиг
}
//---------------------------------------------------
CHugeInteger CHugeInteger::revolution() {
	CHugeInteger c = *this;
	for (int i = 0; i < size; i++) {
		num[i] = c.num[size - 1 - i];    
	}          
	return *this;//переворачивает
}
//---------------------------------------------------
CHugeInteger CHugeInteger::operator /(const CHugeInteger & b) {

	if ((size == 1 && num[0] == 0) || ((*this) < b)) {//если делитель больше делимого или делимое равно 0, то возвращаем элемент s размером 1 =0
		CHugeInteger s(1);
		return s;          
	}
	CHugeInteger temp = this->substring(b.size);//выделит строку размера как делитель
	if (temp < b)
		temp = this->substring(b.size + 1);//если чё +1
	int d = size - temp.size;
	int count1 = 0;        //счётчит номера элемента в ответе
	int count2 = d - 1;    //колво  оставлихся штук которые можно скидывать
	CHugeInteger c(d + 1); //сюда ответ
	for (int j = 0; j < d + 1 ; ++j) {
		for (int i = 2; i <= 10; ++i) {
			if (temp < b.mult(i, 0)) {
				--i;
				c.num[count1] = i;
				++count1;
				temp -= b.mult(i, 0);
				break;                     
			}   
		}
		if (count2 < 0) 
			return (c.revolution());

		temp = temp.addNum(num[count2]);//добавляет номер с конца числа
		--count2;    

		for (int i = 1; i < d + 1; ++i) {
			if (temp < b) {
				if (count2 < 0) {
					c.num[count1] = 0;   
					++count1;
					return (c.revolution());
				}                                     //добавление следующих разрядов до тех пор пока делимое меньше делителя
				temp = temp.addNum(num[count2]);
				--count2;
				c.num[count1] = 0;
				++count1;
			} 
			else
				break;        
		}                 
	}
	return (c.revolution());//показывает ответ во вновь перевёрнутом виде
}

CHugeInteger CHugeInteger::operator %(const CHugeInteger & b) const{
	CHugeInteger temp, a = *this;   
	temp = a / b;
	temp = temp * b;
	if (temp == 0)
		return 0;
	return a - temp;
}     