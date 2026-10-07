import Foundation

let digitalLogic = readLine()!
let tokens = readLine()!.split(separator: " ")
let k = Int(tokens[0])!
let m = Int(tokens[1])!

// Please write your code here.

let bits = Array(digitalLogic).map { Int(String($0))! }
var dict: [Int: Int] = [:]
let mask = (1 << k) - 1
var result = 0

var cur = 0
for i in 0..<bits.count {
    cur = ((cur << 1) | bits[i]) & mask
    if i >= k - 1 {
        dict[cur, default: 0] += 1
        if dict[cur]! >= m {
            result = 1
            break
        }
    }
}

print(result)
