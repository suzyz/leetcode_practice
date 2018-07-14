package p537

import (
	"strconv"
)

type myComplex struct {
	x, y int
}

func complexNumberMultiply(a string, b string) string {

	num1 := unmarshal(a)
	num2 := unmarshal(b)

	res := myComplex{}

	res.x = num1.x*num2.x - num1.y*num2.y
	res.y = num1.x*num2.y + num1.y*num2.x
	return marshal(res)
}

func unmarshal(s string) myComplex {
	num := myComplex{}

	i, isNegative := 0, false

	if s[0] == '-' {
		isNegative = true
		i++
	}

	for s[i] != '+' {
		num.x = 10*num.x + int(s[i]-'0')
		i++
	}

	if isNegative {
		num.x *= -1
	}

	i++
	if s[i] == '-' {
		isNegative = true
		i++
	} else {
		isNegative = false
	}

	for i < len(s)-1 {
		num.y = 10*num.y + int(s[i]-'0')
		i++
	}
	if isNegative {
		num.y *= -1
	}

	return num
}

func marshal(num myComplex) string {
	s := strconv.Itoa(num.x) + "+" + strconv.Itoa(num.y) + "i"
	return s
}
