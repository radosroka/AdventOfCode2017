package main

import (
  "fmt"
  "strings"
)

func abs(x int) (int) {
  if x < 0 {
    return x * -1
  } else {
    return x
  }
}

const MAX_SIZE int = 256

func main() {

  // a -> / b -> \ c -> |
  x, y := 0, 0

  var input string
  fmt.Scan(&input)
  cmds := strings.Split(input, ",")

  m := 0
  for _, v := range cmds {

    if (strings.Compare(v, "ne") == 0) {
      x++
      y++
    } else if (strings.Compare(v, "sw") == 0) {
      x--
      y--
    } else if (strings.Compare(v, "nw") == 0) {
      x--
      y++
    } else if (strings.Compare(v, "se") == 0) {
      x++
      y--
    } else if (strings.Compare(v, "n") == 0) {
      y += 2
    } else if (strings.Compare(v, "s") == 0) {
      y -= 2
    }
    mm := 0
    if (abs(x) == abs(y)) {
      mm = abs(x)
    } else if (x == 0) {
      mm = abs(y)/2
    } else {
      diff := abs(abs(y) - abs(x))
      mm = (diff/2) + abs(x)
    }

    if mm > m {
      m = mm
    }
  }

  fmt.Println(m)
}
