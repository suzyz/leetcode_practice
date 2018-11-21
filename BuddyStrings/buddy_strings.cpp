class Solution {
	public:
		    bool buddyStrings(string A, string B) {
			            if (A.length() != B.length())
					                return false;
				            
				            int n = A.length(), count = 0, idx = -1;
					            for (int i = 0; i < A.length(); ++i) {
							                if (A[i] != B[i]) {
										                ++count;
												                if (count > 2)
															                    return false;
														                
														                if (count == 1)
																	                    idx = i;
																                else {
																			                    if (A[idx] != B[i] || A[i] != B[idx])
																						                            return false;
																					                    }
																		            }
									        }
						            
						            if (count == 2)
								                return true;
							            
							            if (count != 0)
									                return false;
								            
								            vector<int> sum(26);
									            for (int i = 0; i < n; ++i) {
											                ++sum[A[i]-'a'];
													            if (sum[A[i]-'a'] > 1)
															                    return true;
														            }
										            
										            return false;
											        }
};
