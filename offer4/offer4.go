package offer4

func findNumberIn2DArray(matrix [][]int, target int) bool {
	if len(matrix) == 0 {
		return false
	}
	rows := len(matrix)
	columns := len(matrix[0])
	row := 0
	column := columns - 1

	for row < rows && column >= 0 {
		if matrix[row][column] == target {
			return true
		}
		if matrix[row][column] > target {
			column--
		} else {
			row++
		}
	}

	return false
}
