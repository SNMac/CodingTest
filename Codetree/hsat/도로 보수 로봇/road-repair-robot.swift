import Foundation

let firstLine = readLine()!
let firstInputs = firstLine.split(separator: " ").map { Int($0)! }
let n = firstInputs[0]
let k = firstInputs[1]

let secondLine = readLine()!
let positions = secondLine.split(separator: " ").map { Int($0)! }

// Please write your code here.

func canCover(_ len: Int) -> Bool {
    var count = 0
    var i = 0
    while i < n {
        count += 1
        if count > k { return false }
        
        let end = positions[i] + len - 1
        while i < n && positions[i] <= end {
            i += 1
        }
    }
    return true
}

var low = 1
var high = positions[0] + positions[n - 1] + 1

while low < high {
    let mid = (low + high) / 2
    if canCover(mid) {
        high = mid
    } else {
        low = mid + 1
    }
}

print(low)
