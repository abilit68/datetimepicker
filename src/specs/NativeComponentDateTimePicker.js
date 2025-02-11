// @flow strict-local
import type {ViewProps} from 'react-native/Libraries/Components/View/ViewPropTypes';
import type {ColorValue} from 'react-native/Libraries/StyleSheet/StyleSheet';
import type {HostComponent} from 'react-native';

import type {
  BubblingEventHandler,
  Double,
  Int32,
  WithDefault,
} from 'react-native/Libraries/Types/CodegenTypes';
import codegenNativeComponent from 'react-native/Libraries/Utilities/codegenNativeComponent';

type DateTimePickerEvent = $ReadOnly<{|
  timestamp: Double,
  utcOffset: Int32,
|}>;

type NativeProps = $ReadOnly<{|
  ...ViewProps,
  onChange?: ?BubblingEventHandler<DateTimePickerEvent>,
  onPickerDismiss?: ?BubblingEventHandler<null>,
  maximumDate?: ?Double,
  minimumDate?: ?Double,
  date?: ?Double,
  locale?: ?string,
  minuteInterval?: ?Int32,
  mode?: WithDefault<'date' | 'time' | 'datetime' | 'countdown', 'date'>,
  timeZoneOffsetInMinutes?: ?Double,
  timeZoneName?: ?string,
  textColor?: ?ColorValue,
  accentColor?: ?ColorValue,
  themeVariant?: WithDefault<'dark' | 'light' | 'unspecified', 'unspecified'>,
  displayIOS?: WithDefault<
    'default' | 'spinner' | 'compact' | 'inline',
    'default',
  >,
  is24Hour?: WithDefault<boolean, true>,
  enabled?: WithDefault<boolean, true>,
|}>;

export default (codegenNativeComponent<NativeProps>('RNDateTimePickerView', {
  excludedPlatforms: ['android'],
}): HostComponent<NativeProps>);
