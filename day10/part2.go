package main

import (
  "fmt"
)

func reverse(arr []byte, sublist_size int, pos int)  {
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
  var numbers = make([]byte, MAX_SIZE)

  for index := 0 ; index < MAX_SIZE ; index++ {
    numbers[index] = byte(index)
  }

//  fmt.Println(numbers)

  var input string
  fmt.Scan(&input)

  var suffix = [...]byte {17, 31, 73, 47, 23}
  var arr = append([]byte(input), suffix[:]...)

  fmt.Println(arr)

  //fmt.Println(arr)

  var pos int = 0
  var skip int = 0
  for i := 0; i < 64; i++ {

    for _,value := range arr {
    //  fmt.Println("1. ", numbers, pos, value)
      reverse(numbers, int(value), pos)
      pos = (pos + int(value) + skip) % len(numbers)
      skip++
    //  fmt.Println("2. ", numbers, pos, value)
    }
  }

  var xored [16]byte

  for i := 0; i < 16; i++ {
    var x byte = numbers[i*16]
    for j := 1; j < 16; j++ {
      x ^= numbers[i*16 + j]
    }
    xored[i] = x
  }

  for i := 0; i < 16; i++ {
    fmt.Printf("%x",xored[i])
  }
  fmt.Print("\n")
}
