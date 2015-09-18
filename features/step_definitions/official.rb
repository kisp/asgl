Given(/^official testcase "(.*?)"$/) do |name|
  copy_to_tmp_auba("data/iccma15_testcases/#{name}.apx")
  copy_to_tmp_auba("data/iccma15_solutions/#{name}.EE-GR")
  copy_to_tmp_auba("data/iccma15_solutions/#{name}.EE-CO")
  copy_to_tmp_auba("data/iccma15_solutions/#{name}.EE-ST")
  copy_to_tmp_auba("data/iccma15_solutions/#{name}.EE-PR")
end

Given(/^apx testcase "(.*?)"$/) do |name|
  copy_to_tmp_auba("data/apx/#{name}.apx")
  copy_to_tmp_auba("data/apx/#{name}.EE-GR")
  copy_to_tmp_auba("data/apx/#{name}.EE-CO")
  copy_to_tmp_auba("data/apx/#{name}.EE-ST")
  copy_to_tmp_auba("data/apx/#{name}.EE-PR")
end

Then(/^the output should be eql to solution "(.*?)"$/) do |name|
  path = "tmp/aruba/#{name}"
  raise "#{path} does not exit" unless File.exist?(path)
  a = parse_output(all_stdout)
  b = parse_output(File.read(path))
  expect(a).to be_meql(b)
end
