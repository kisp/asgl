def beginp line
  line =~ /BEGIN_SRC/  
end

def beginp_tangle line
  line =~ /BEGIN_SRC.*tangle.*yes/  
end

def endp line
  line =~ /END_SRC/
end

def fix line
  line.gsub(/,#+/, "#+")
end

def ls line
  if beginp_tangle line
    :begin
  elsif endp line
    :end
  else
    :text
  end
end

$state = :text

File.readlines(ARGV[0]).each do |line|
  ls = ls line
  if $state == :text

    if ls == :text
    elsif ls == :begin
      $state = :src
    elsif ls == :end      
    end

  elsif

    if ls == :text
      puts (fix line)
    elsif ls == :begin
      raise "foo"
    elsif ls == :end
      puts
      puts
      $state = :text
    end
    
  end
end
