import Foundation

let inp = readLine()!.components(separatedBy: [" "]).map { $0 }
let (s1, a) = (inp[0], Int(inp[1])!)

var str = ""
for i in 0..<a {
    str.append(s1)
}
print(str)
