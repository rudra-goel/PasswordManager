import LocalAuthentication
import Cocoa


let context = LAContext()

var error: NSError?

extension String {
    func fileName() -> String {
        return URL(fileURLWithPath: self).deletingPathExtension().lastPathComponent
    }

    func fileExtension() -> String {
        return URL(fileURLWithPath: self).pathExtension
    }
}

guard context.canEvaluatePolicy(.deviceOwnerAuthentication, error: &error) else {
    print(error?.localizedDescription ?? "Can't evaluate policy")
    throw NSError()
}

func genAuthKey(outputFile: String, key: String){
    let fileExtension = outputFile.fileExtension()
    let fileName = outputFile.fileName()

    //get file url
    let fileUrl = try! FileManager.default.url(for: .desktopDirectory, in: .userDomainMask, appropriateFor: nil, create: true)
    let ooutputFile = fileUrl.appendingPathComponent(fileName).appendingPathExtension(fileExtension)
    //save data
    guard let data = key.data(using: .utf8) else {
        print("Failed to generate authentication key")
        return
    }

    do {
        guard let url = URL(string: outputFile) else {
            print("URL CONVERSION ERROR")
            return
        }
        try data.write(to: url)
        print("Authentication key generated")
    } catch {
        print(error.localizedDescription)
        
    }

}


let authenticate = Task {
    do {
        try await context.evaluatePolicy(.deviceOwnerAuthentication, localizedReason: "Log in to your account")

        genAuthKey(outputFile: "/Users/rgoel/Downloads/pass-mgr/AuthKey.txt", key: "Cum")
        return true
    } catch let error {
        print(error.localizedDescription)
        return false

        // Fall back to a asking for username and password.
        // ...
    }
}

print(await authenticate.value)

