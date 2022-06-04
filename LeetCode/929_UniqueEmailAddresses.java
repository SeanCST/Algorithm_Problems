class Solution {
    public int numUniqueEmails(String[] emails) {
        HashSet<String> set = new HashSet<>();
        for(String email : emails) {
            String[] localAndDomainName = email.split("@");
            String localName = localAndDomainName[0];
            String domainName = localAndDomainName[1];
            
            if(localName.contains(".")) {
                localName = localName.replace(".", "");
            }
            if(localName.contains("+")) {
                localName = localName.substring(0, localName.indexOf('+'));
            }
            set.add(localName + "@" + domainName);
        }

        return set.size();
    }
}