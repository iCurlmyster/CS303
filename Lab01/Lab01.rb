#!/usr/bin/ruby


# create a global array to store all of the number values from the file
$test_array = Array.new
# open file passed in as argument and iterate through each line
open(ARGV[0]).each do |number|
	# split line on whitespaces and save to variable
	num_array = number.split /\s+/
	# go through array and push elements into global array variable
	num_array.each do |n|
		$test_array << n.to_i
	end
end

# give some space in terminal
puts"\n"

puts "Search for what number? "
# get user input and convert to integer value 
user_in = $stdin.gets.chomp.to_i
# set boolean variable to initial false value for linear search loop
did_find = false

puts "Linear search for #{user_in}"
# capture Time at current moment before linear search
start_time = Time.now
# iterate through global array accompanied by index
$test_array.each_with_index do |num, index|
	# if element equals what the user was looking for
	if num == user_in then
		puts "#{num} was found in array at index #{index}"
		# set boolean to true to let script know that value was found
		did_find = true
		# break out of loop to not continue all the way to end
		break
	end
end
# capture Time at current moment after linear search is done
end_time = Time.now
# calculate final time
final_time = end_time - start_time
puts ""
# print to screen final time
puts "Linear search took this long in seconds: #{final_time}"
puts ""
# if did_find boolean still set to false then value was never found
if did_find == false then
	puts "item was not found"
end
puts "\n"

# sort array so we can do binary search now
$test_array.sort!

puts"\n"
puts ""
puts "Binary search for #{user_in}"

# defining a method to handle binary search 
# @param user_input
# @param high 
# @param mid
# @param low
# @return boolean
def binary_search user_input, high, mid, low
	# if user_input equals element at mid index then found
	if user_input == $test_array[mid] then
		puts "#{user_input} was found in array at index #{mid}"
		return 1
	end
	# if high <= low then item is not in array
	if high <= low then 
		puts "item not found"
		return 0
	end

	# if user_input is less than element at index mid then search in elements lower than that index
	if user_input < $test_array[mid] then
		# calculate new mid by adding low value to the new top boundary value and dividing it by two
		return binary_search user_input, mid - 1, ((low+(mid - 1))/2), low
	elsif user_input > $test_array[mid]
		# calculate new mid by adding new lower bound value to high value and dividing it by two
		return binary_search user_input, high, (((mid + 1)+high)/2), mid + 1
	end
end
# get initial upper bound value
high = $test_array.count - 1

# capture Time at current moment before binary search
start_time = Time.now
binary_search user_in, high, high/2, 0
# capture Time at current moment after binary search
end_time = Time.now
# calculate final time
final_time = end_time - start_time
puts ""
# print out to the screen how long it took
puts "Binary search took this long in seconds: #{final_time}"
puts ""

