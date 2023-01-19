class Solution {
    public boolean strongPasswordCheckerII(String password) {
        if(password.length() < 8) {
            return false;
        }
        String specialCharacters = "!@#$%^&*()-+";
        boolean hasLowercase = false, hasUppercase = false, 
                hasDigit = false, hasSpecialCharacter = false;
        for(int i = 0; i < password.length(); i++) {
            char c = password.charAt(i);
            if(i > 0 && c == password.charAt(i - 1)) {
                return false;
            }
            if(c >= 'a' && c <= 'z') {
                hasLowercase = true;
            } else if(c >= 'A' && c <= 'Z') {
                hasUppercase = true;
            } else if(c >= '0' && c <= '9') {
                hasDigit = true;
            } else if(specialCharacters.contains(String.valueOf(c))) {
                hasSpecialCharacter = true;
            }
        }

        return hasLowercase && hasUppercase && hasDigit && hasSpecialCharacter;
    }
}