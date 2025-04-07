import Foundation

func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    var genreTotalPlayDict = [String: Int]()  // [genre: play]
    var genreIndexDic = [String: [(index: Int, play: Int)]]()
    var answer = [Int]()
    
    for (i, genre) in genres.enumerated() {
        let play = plays[i]
        genreTotalPlayDict[genre] = genreTotalPlayDict[genre, default: 0] + play
        
        if genreIndexDic.keys.contains(genre) {
            genreIndexDic[genre]!.append((index: i, play: play))
        } else {
            genreIndexDic[genre] = [(index: i, play: play)]
        }
    }
    
    let sortedTotalPlayDict = genreTotalPlayDict.sorted(by: { $0.value > $1.value })
    
    for genre in sortedTotalPlayDict {
        genreIndexDic[genre.key]!.sort(by: { $0.play > $1.play })
    }
    print(genreIndexDic)
    
    for element in sortedTotalPlayDict {
        for song in genreIndexDic[element.key]!.prefix(2) {
            answer.append(song.index)
        }
    }
    
    return answer
}
