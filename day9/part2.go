package main

import "fmt"

var score int64 = 0

func getFirst(str *string) (byte) {
  var ch byte = 0
  if len(*str) > 0 {
    ch = (*str)[0]
    *str = (*str)[1:]
  }
  return ch
}

func eatMess(str *string) {

  var flag bool = true
  for {
    var x byte = getFirst(str)

    score++

    if flag && x == '>' {
      score--
      break
    }

    if flag && x == '!' {
      flag = false
      score--
      continue
    }

    if !flag {
      score--
      flag = true
    }

  }
}

func recursive(str *string, r int64) {

  if len(*str) <= 0 {
    return
  }

  r += 1
  //score += r

  // /fmt.Printf("recursive: %s | %d | %d \n", (*str), r, score)

  var x byte = 0

  for {
    x = getFirst(str)
    if x == 0 {
      break
    }

  //  fmt.Printf("recursive loop: %s | %c \n", (*str), x)

    switch x {
      case '{':
        recursive(str, r)
        continue
      case '}':
        break
      case ',':
        continue
      case '<':
        eatMess(str)
        continue
      default:
        break
    }
    break
  }

  //fmt.Printf("recursive_end: %s | %d | %d \n", (*str), r, score)
}

func main() {
  var input string
  var r int64 = -1
  fmt.Scanln(&input)
  //fmt.Println(input)
  recursive(&input, r)

  fmt.Println(score)
}
