package p273

import (
	"strings"
)

var LessThanTwenty [20]string = [20]string{"Zero", "One", "Two", "Three", "Four", "Five",
	"Six", "Seven", "Eight", "Nine", "Ten",
	"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
	"Sixteen", "Seventeen", "Eighteen", "Nineteen"}

var Tens [10]string = [10]string{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}
var Thousands [4]string = [4]string{"", "Thousand", "Million", "Billion"}

func numberToWords(num int) string {
	if num == 0 {
		return "Zero"
	}

	ans := ""
	i := 0
	for num > 0 {
		if num%1000 != 0 {
			ans = helper(num%1000) + Thousands[i] + " " + ans
		}
		num /= 1000
		i++
	}

	return strings.TrimSpace(ans)
}

func helper(num int) string {
	res := ""

	if num >= 100 {
		res += LessThanTwenty[num/100] + " Hundred" + " "
		num %= 100
	}
	if num >= 20 {
		res += Tens[num/10] + " "
		num -= 10 * (num / 10)
	}
	if num > 0 {
		res += LessThanTwenty[num] + " "
	}
	return res
}
