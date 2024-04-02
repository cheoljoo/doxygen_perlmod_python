# BEGIN {push @INC, '..'}
use lib '.';
use DoxyDocs;

our %init4py;

sub change_special_code {
	my ($s) = @_;
	$s =~ s/\'/\\\'/g;
	return $s;
}

sub generate_cc($$) {
	my $str = $_[0];
	my $doc = $_[1];
	my $cnt = 1;

	my $ps = $str;
	$ps =~ s/\{\s*/\[\'/g;
	$ps =~ s/\s*\}/\'\]/g;
	$ps =~ s/^\$//;

	#print "generate_cc $doc\n";
	if($doc =~ /^HASH\(/){
		#print PH "=== $ps\n";
		if($init4py{$ps} eq ""){
			print PH "$ps={}\n";
			$init4py{$ps} = "init";
		}
		#print "HASH " . %{$doc} . "\n";
		foreach $key (keys %{$doc}) {
			if( not ( (${$doc}{$key} =~ /^ARRAY\(/) || (${$doc}{$key} =~ /^HASH\(/) ) ){
				#print "hash $str { $key } = value( ${$doc}{$key} )\n";
				print PH "$ps ['$key'] =  \'\'\'" . change_special_code(${$doc}{$key}) . "\'\'\'\n";
				 #print PH "$ps ['$key'] =  \"" . change_special_code(${$doc}{$key}) . "\"\n";
			} else {
				generate_cc("$str { $key }",  ${$doc}{$key});
			}
		}
	} elsif($doc =~ /^ARRAY\(/){
		#print "ARRAY @$doc\n";
		#print PH "=== $ps\n";
		if($init4py{$ps} eq ""){
			print PH "$ps={}\n";
			$init4py{$ps} = "init";
		}
		foreach $key (@{$doc}) {
			#print "array $cnt key( $key )\n";
			#print "array $doc->{$key}\n";
			if( not ( ($key =~ /^ARRAY\(/) || ($key =~ /^HASH\(/) ) ){
				#print "hash $str { $key } = value( ${$doc}{$key} )\n";
				print  "ARRAY $str [ $key ] =  \'\'\'" . change_special_code(${$doc}[$key]) . "\'\'\'\n";
			} else {
				generate_cc("$str { $cnt }",$key);
				$cnt ++;
			}
		}
	} else {
		print PH ">>> $ps\n";
		#print "DOC $str $doc\n";
		#print "DOC $str @{$doc}\n";
		#print "DOC $str %{$doc}\n";
	}
}


print STDERR "input DoxyDocs.pm  output filename = DoxyDocs.py\n";
open(PH, ">","DoxyDocs.py") or die "Can't open < DoxyDocs.py : $!";
#generate($doxydocs, $doxystructure);
generate_cc("\$D",$doxydocs);
close PH;
print STDERR "DoxyDocs.py has variable of D dictionary including all DoxyDocs.pm\n";

