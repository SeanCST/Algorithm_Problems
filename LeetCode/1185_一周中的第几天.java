class Solution {
    public String dayOfTheWeek(int day, int month, int year) {
        // 1971.1.1 是星期五
        String daysOfWeek[] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
        
        int days = 0;
        for(int y = 1971; y < year; y++) {
            if(isLeapYear(y)) {
                days += 366;
            } else {
                days += 365;
            }
        }

        for(int m = 1; m < month; m++) {
            if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
                days += 31;
            } else if(m == 2) {
                if(isLeapYear(year)) {
                    days += 29;
                } else {
                    days += 28;
                }
            } else {
                days += 30;
            }
        }

        days += day - 1;

        return daysOfWeek[days % 7];
    }

    private Boolean isLeapYear(int year) {
        return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
    }
}