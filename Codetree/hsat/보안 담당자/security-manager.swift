import Foundation

let n = Int(readLine()!)!
let record = readLine()!

// Please write your code here.

var enterLow = 0
var enterHigh = 0
var result = "Yes"

for char in record {
    switch char {
    case "(":
        enterLow += 1
        enterHigh += 1
    case ")":
        enterLow -= 1
        enterHigh -= 1
    default: // "?"
        enterLow -= 1
        enterHigh += 1
    }
    
    if enterHigh < 0 {
        result = "No"
        break
    }
    
    if enterLow < 0 { enterLow = 1 }
}

if enterLow != 0 { result = "No" }

print(result)
