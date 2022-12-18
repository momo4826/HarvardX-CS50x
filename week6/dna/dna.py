import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Wrong uasage")
        return
    csv_file, txt_file = sys.argv[1:]

    data = []
    with open(csv_file) as content:
        reader = csv.DictReader(content)
        for item in reader:
            # print(item)
            data.append(item)

    seq = ""
    with open(txt_file) as content:
        for item in content.readlines():
            seq += item
    seq = seq.strip()
    # print(seq)

    subseqs = list(data[0].keys())[1:]
    count = [longest_match(seq, subseq) for subseq in subseqs]
    result = dict(zip(subseqs, count))

    for row in data:
        flag = 0
        for key, value in result.items():
            if int(row[key]) == value:
                flag += 1
            else:
                break
        if flag == len(subseqs):
            print(row['name'])
            return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
