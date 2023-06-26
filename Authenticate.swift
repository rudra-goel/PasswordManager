import LocalAuthentication

func auth(){

    var context = LAContext()


    var biometry = context.biometryType
    var error: NSError?

    // Check for biometric authentication 
    // permissions
    var permissions = context.canEvaluatePolicy(.deviceOwnerAuthentication, error: &error)

    if permissions {
        // Proceed to authentication
        print("Happy Access")
        let reason = "Log in with Touch ID"
        context.evaluatePolicy(.deviceOwnerAuthenticationWithBiometrics, localizedReason: reason) { 
                success, evaluateError in
                    
                    if success {
                        
                        //TODO: User authenticated successfully, take appropriate action
                        print("Cum")
                        
                    } else {
                        //TODO: User did not authenticate successfully, look at error and take appropriate action
                        print("No Cum")
                        guard let error = evaluateError else {
                            print("err")
                            return
                        }
                    }

                    print("bad")
                        
        }
    }
    else {
        print("No Access")
        // Handle permission denied or error
    }

}

auth()


