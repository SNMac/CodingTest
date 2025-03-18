import Foundation

let s1 = readLine()!

var str = ""
for c in s1 {
    if c.isLowercase {
        str.append(c.uppercased())
    } else {
        str.append(c.lowercased())
    }
}
print(str)