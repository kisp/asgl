require 'aruba/cucumber'
require 'set'

Before do
  @aruba_timeout_seconds = 10
end

RSpec::Matchers.define :be_meql do |expected|
  match do |actual|
    actual.meql(expected)
  end
  failure_message do |actual|
    "but got #{actual.inspect}"
  end
end

RSpec::Matchers.define :be_meql_verbose do |expected|
  match do |actual|
    actual.meql(expected)
  end
  failure_message do |actual|
    "which evals to #{expected}\nbut got #{actual.inspect}"
  end
end

RSpec::Matchers.define :be_included_with_meql do |expected|
  match do |actual|
    expected.any? {|e| e.meql(actual) }
  end
  failure_message do |actual|
    "but got #{actual.inspect}"
  end
end

class Set
  def meql(other)
    result = other.is_a?(Set) &&
             (self.size == other.size) &&
             self.all? {|elem| other.any? {|q| q.meql(elem) } }
    # p "meql of #{self} and #{other} is #{result}"
    result
  end
end

class String
  def meql(other)
    other.is_a?(String) &&
      self == other
  end
  def j2set
    case self
    when "YES"
      true
    when "NO"
      false
    else
      self
    end
  end
end

class Array
  def j2set
    a = self.map do |x|
      x.j2set
    end
    unless a.size == a.uniq.size
      raise "contains duplicates: #{a}"
    end
    a.to_set
  end
end

class TrueClass
  def meql(other)
    other == true
  end
end

class FalseClass
  def meql(other)
    other == false
  end
end

def convert_to_json(string)
  string.gsub(/([^\[, \n\]]+)/, '"\1"')
end

def parse_output(string)
  json = MultiJson.load(convert_to_json(string))
  json.j2set
end

def is_array_of_strings?(x)
  x.is_a?(Array) &&
    x.all? { |elem| elem.is_a?(String) }
end

def is_set_of_strings?(x)
  is_array_of_strings?(x) &&
    x.uniq.length == x.length
end

def copy_to_tmp_auba(path)
  raise "tmp/aruba does not exit" unless File.exist?("tmp/aruba")
  system("cp #{path} tmp/aruba")
  raise "cp of #{path} to tmp/aruba failed" unless $?.success?
end
