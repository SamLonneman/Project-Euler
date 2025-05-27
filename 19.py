# Initialize a counter for sundays of interest
c = 0

# We are given that January 1, 1900 was a Monday
day = 2 # 1:Sunday, 2:Monday, etc.
date = 1
month = 1
year = 1900

# Begin counting upwards towards 2000
while year <= 2000:

    # Print current date details for debugging
    # print(f'{day}: {month}/{date}/{year}')

    # Begin counting Sundays on the first of the month starting in 1901
    if year >= 1901:
        c += day == 1 and date == 1

    # Increment the day of the week
    if day == 7:
        day = 0
    day += 1

    # If we reach the end of the month (for any reason)
    if (
            (date == 28 and month == 2 and not ((year % 100 != 0 and year % 4 == 0) or year % 400 == 0)) or # Feb 28th (non leap year)
            (date == 29 and month == 2) or                                                                  # 29th of February
            (date == 30 and month in (4, 6, 9, 11)) or                                                      # 30th of the 30 day months
            (date == 31)                                                                                    # 31st of any month
        ):

        # Roll over the date
        date = 0

        # If we reach the end of the year
        if month == 12:

            # Roll over month
            month = 0

            # Increment year
            year += 1

        # Increment month
        month += 1

    # Increment date
    date += 1

print(c)