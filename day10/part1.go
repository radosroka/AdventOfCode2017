package main

import (
  "fmt"
  "strings"
  "strconv"
)

func reverse(arr []int, sublist_size int, pos int)  {
  for i := 0 ; i < sublist_size / 2 ; i++ {
    var plus int = (pos + i) % len(arr)
    var minus int = (pos + sublist_size - i - 1) % len(arr)

    tmp := arr[plus]
    arr[plus] = arr[minus]
    arr[minus] = tmp
  }

  //fmt.Println("--", arr, "--")
}

const MAX_SIZE int = 256

func main() {
  var numbers = make([]int, MAX_SIZE)

  for index := 0 ; index < MAX_SIZE ; index++ {
    numbers[index] = index
  }

//  fmt.Println(numbers)

  var input string
  fmt.Scan(&input)
  tmp := strings.Split(input, ",")

  var arr = make([]int, len(tmp))

  for i,_ := range tmp {
    arr[i], _ = strconv.Atoi(tmp[i])
  }

  //fmt.Println(arr)

  var pos int = 0
  var skip int = 0
  for _,value := range arr {
  //  fmt.Println("1. ", numbers, pos, value)
    reverse(numbers, value, pos)
    pos = (pos + value + skip) % len(numbers)
    skip++
  //  fmt.Println("2. ", numbers, pos, value)
  }

  //reverse(numbers, 4, 3)

  fmt.Println(numbers[0] * numbers[1])

}
