package main

import (
  "fmt"
  "bufio"
  "os"
  "strings"
  "strconv"
)

func Readln(r *bufio.Reader) (string, error) {
  var (isPrefix bool = true
       err error = nil
       line, ln []byte
      )
  for isPrefix && err == nil {
      line, isPrefix, err = r.ReadLine()
      ln = append(ln, line...)
  }
  return string(ln),err
}

func contains(s []int, e int) bool {
    for _, a := range s {
        if a == e {
            return true
        }
    }
    return false
}



func main() {
  r := bufio.NewReader(os.Stdin)

  m := make(map[int][]int)

  group := make(map[int]int)

  for {
    var line string
    line, err := Readln(r)
    if err != nil {
      break
    }
    var program int
    fmt.Sscanf(line, "%d", &program)

    arr := strings.Split(line, " ")[2:]
    programs := make([]int, len(arr))
    for i := range arr {
      arr[i] = strings.TrimSuffix(arr[i], ",")
      programs[i], _ = strconv.Atoi(arr[i])
    }
    m[program] = programs

  }

  processed := make([]int, 0)
  processed = append(processed, 0)
  group[0] = 0
  for _,v := range m[0] {
    group[v] = 0
  }

  for {
//    fmt.Println(group)
    for i,_ := range group {
      if contains(processed, i) {
        continue
      }

      for _,v := range m[i] {
        group[v] = 0
      }
      processed = append(processed, i)
//    fmt.Println(group)
      break
    }

//    fmt.Println(processed)
//    fmt.Println(len(processed), "==", len(group))

    if len(processed) == len(group) {
//       fmt.Println("breaked")
      break
    }
  }

  fmt.Println(processed)
  fmt.Println(len(processed))
}
