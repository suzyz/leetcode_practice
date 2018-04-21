package p273

func numberToWords(num int) string {
	LessThanTwenty := [20]string{"Zero", "One", "Two", "Three", "Four", "Five",
		"Six", "Seven", "Eight", "Nine", "Ten",
		"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
		"Sixteen", "Seventeen", "Eighteen", "Nineteen"}

	Tens := [10]string{"Ten", "Twenty", "Thiry", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}
	Larges := [4]string{"Hundred", "Thousand", "Million", "Billion"}

	ans := ""
	if num >= 1e9 {
		ans += LessThanTwenty[num/(1e9)] + Larges[3]
		num -= num / (1e9) * (1e9)
	}
	if num >= 1e6 {
		tmp := 
	}
}
