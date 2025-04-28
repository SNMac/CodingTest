import Foundation

func solution(_ id_list:[String], _ report:[String], _ k:Int) -> [Int] {
    /// 신고 중복 없앤 Set
    var reportSet = Set<String>()
    /// [유저 ID : [유저가 신고한 ID]]
    var reportDict = [String: [String]]()
    /// [유저 ID: 신고당한 횟수]
    var reportedIDDict = [String: Int]()
    /// 처리 결과 메일 받은 횟수
    var answer = [Int](repeating: 0, count: id_list.count)
    
    report.forEach {
        reportSet.insert($0)
    }
    
    reportSet.forEach {
        let splited = $0.split(separator: " ")
        let userID = String(splited.first!)
        let reportedID = String(splited.last!)
        reportDict[userID, default: []].append(reportedID)
        reportedIDDict[reportedID, default: 0] += 1
    }
    
    for (i, userID) in id_list.enumerated() {
        // 유저 ID가 신고한 ID 배열 가져옴
        guard let reportedIDList = reportDict[userID] else { continue }
        
        for reportedID in reportedIDList {
            // 신고한 ID 배열에서 k번 이상이면 처리 결과 메일 +1
            if let reportedCount = reportedIDDict[reportedID], reportedCount >= k {
                answer[i] += 1
            }
        }
    }
    
    return answer
}
