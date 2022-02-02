package offer5

func replaceSpace(s string) string {
	ret := ""
	for _, i := range s {
		if i == ' ' {
			ret += "%20"
		} else {
			ret += string(i)
		}
	}
	return ret
}
