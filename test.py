def predict_thresholds(Vcc, Rf, Rg):
# When output = Vcc (high), node voltage due to Rf||Rg divider:
V_high_node = Vcc * (Rg / (Rf + Rg))
# When output = 0 (low), node voltage is 0 via Rg (but with Rf to 0 => 0)V_low_node = 0.0
# For a realistic circuit, the input driver must exceed these node levels to switch.
# Return these as approximate thresholds:
return V_low_node, V_high_node
# Example usage:
Vcc = 5.0
Rf = 100e3
Rg = 47e3
vlow, vhigh = predict_thresholds(Vcc, Rf, Rg)
print(f"Approx thresholds: low={vlow:.3f} V, high={vhigh:.3f} V")